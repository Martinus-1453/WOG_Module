#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

#include "api/squirrel_api.h"
#include "api/module_api.h"

using namespace SqModule;

namespace nonut
{
	template <typename T>
	T GetProperty(HSQOBJECT& object, std::string& name)
	{
		T result{};

		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getvalue(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return result;
	}

	template <>
	inline bool GetProperty<bool>(HSQOBJECT& object, std::string& name)
	{
		return GetProperty<SQBool>(object, name);
	}

	template <>
	inline std::string GetProperty<std::string>(HSQOBJECT& object, std::string& name)
	{
		const SQChar* result{};

		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getstring(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return result;
	}


	template <typename T>
	void SetProperty(HSQOBJECT& object, std::string& name, T value)
	{
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());
		sq_pushvalue(vm, value);

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template <typename T>
	class Property
	{
	public:
		Property(std::string propertyName, const HSQOBJECT object) : object(object),
		                                                             propertyName(std::move(propertyName))
		{
		}

		T Get()
		{
			return GetProperty<T>(object, propertyName);
		}

		void Set(T value)
		{
			SetProperty<T>(object, propertyName, value);
		}

	private:
		HSQOBJECT object;
		std::string propertyName;
	};
}
#endif // PROPERTY_H
