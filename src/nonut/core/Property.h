#ifndef NONUT_CORE_PROPERTY_H
#define NONUT_CORE_PROPERTY_H

#include <string>

#include "squirrel_api.h"
#include "module_api.h"
#include "Utils.h"
#include "Class.h"

using namespace SqModule;

namespace nonut
{
	template <typename T>
	T getProperty(SQObject& object, String& name)
	{
		const auto top = sq_gettop(vm);

		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if constexpr (std::derived_from<T, Class>)
		{
			SQObject intermediateResult{};
			if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
			{
				sqGetValue(vm, -1, &intermediateResult);
				sq_pop(vm, 1); // pops result
			}

			sq_pop(vm, 1); // pops object
			sq_settop(vm, top);
			return T(intermediateResult);
		}
		else
		{
			T result{};

			if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
			{
				sqGetValue(vm, -1, &result);
				sq_pop(vm, 1); // pops result
			}

			sq_pop(vm, 1); // pops object
			sq_settop(vm, top);
			return result;
		}
	}

	template <>
	inline bool getProperty<bool>(SQObject& object, String& name)
	{
		return getProperty<Bool>(object, name);
	}

	template <>
	inline String getProperty<String>(SQObject& object, String& name)
	{
		const Int top = sq_gettop(vm);
		const SQChar* result{};

		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getstring(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object
		sq_settop(vm, top);
		return result;
	}


	template <typename T>
	void setProperty(SQObject& object, String& name, T value)
	{
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());
		if constexpr (std::derived_from<T, Class>)
		{
			sqPushValue(vm, value.getInstance());
		}
		else
		{
			sqPushValue(vm, value);
		}
		

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template <typename T, bool IsReadOnly = false>
	class Property
	{
	public:
		Property(String propertyName, const SQObject object) : object(object),
		                                                             propertyName(std::move(propertyName))
		{
		}

		Property<T>& operator=(const T& other) noexcept
		{
			set(other);
			return *this;
		}

		operator T()
		{
			return this->get();
		}

		T get()
		{
			return getProperty<T>(object, propertyName);
		}

		void set(T value)
		{
			static_assert(!IsReadOnly, "Cannot set read-only property.");
			setProperty<T>(object, propertyName, value);
		}

	private:
		SQObject object;
		String propertyName;
	};
}
#endif // NONUT_CORE_PROPERTY_H
