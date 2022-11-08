#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

#include "api/squirrel_api.h"
#include "api/module_api.h"

using namespace SqModule;

namespace nonut {

	template<typename T>
	T GetProperty(HSQOBJECT& object, std::string& name)
	{
		return T();
	}

	template<>
	inline bool GetProperty<bool>(HSQOBJECT& object, std::string& name)
	{
		SQBool result = false;
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getbool(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return static_cast<bool>(result);
	}

	template<>
	inline int GetProperty<int>(HSQOBJECT& object, std::string& name)
	{
		int result = 0;
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getinteger(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return result;
	}

	template<>
	inline float GetProperty<float>(HSQOBJECT& object, std::string& name)
	{
		float result = 0.f;
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getfloat(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return result;
	}

	template<>
	inline std::string GetProperty<std::string>(HSQOBJECT& object, std::string& name)
	{
		const SQChar* result = nullptr;
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sq_getstring(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object

		return std::string(result);
	}


	template<typename T>
	void SetProperty(HSQOBJECT& object, std::string& name, T value)
	{
	}

	template<>
	inline void SetProperty<bool>(HSQOBJECT& object, std::string& name, bool value)
	{
		sq_pushobject(vm, object);

		sq_pushstring(vm, name.c_str(), name.length());

		sq_pushbool(vm, value);

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template<>
	inline void SetProperty<int>(HSQOBJECT& object, std::string& name, int value)
	{
		sq_pushobject(vm, object);

		sq_pushstring(vm, name.c_str(), name.length());

		sq_pushinteger(vm, value);

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template<>
	inline void SetProperty<float>(HSQOBJECT& object, std::string& name, float value)
	{
		sq_pushobject(vm, object);

		sq_pushstring(vm, name.c_str(), name.length());

		sq_pushfloat(vm, value);

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template<>
	inline void SetProperty<std::string>(HSQOBJECT& object, std::string& name, std::string value)
	{
		sq_pushobject(vm, object);

		sq_pushstring(vm, name.c_str(), name.length());

		sq_pushstring(vm, value.c_str(), value.length());

		auto result = sq_set(vm, -3); // pops name and value

		sq_pop(vm, 1); // pops object
	}

	template<typename T>
	class Property
	{
	public:
		Property(std::string propertyName, const HSQOBJECT object) : object(object), propertyName(propertyName)
		{
		}
		~Property()
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
