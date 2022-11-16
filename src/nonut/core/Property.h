#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

#include "api/squirrel_api.h"
#include "api/module_api.h"
#include "Utils.h"

using namespace SqModule;

namespace nonut
{
	template <typename T>
	T getProperty(HSQOBJECT& object, std::string& name)
	{
		const SQInteger top = sq_gettop(vm);
		T result{};

		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());

		if (SQ_SUCCEEDED(sq_get(vm, -2))) // pops property
		{
			sqGetValue(vm, -1, &result);
			sq_pop(vm, 1); // pops result
		}

		sq_pop(vm, 1); // pops object
		sq_settop(vm, top);
		return result;
	}

	template <>
	inline bool getProperty<bool>(HSQOBJECT& object, std::string& name)
	{
		return getProperty<SQBool>(object, name);
	}

	template <>
	inline std::string getProperty<std::string>(HSQOBJECT& object, std::string& name)
	{
		const SQInteger top = sq_gettop(vm);
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
	void setProperty(HSQOBJECT& object, std::string& name, T value)
	{
		sq_pushobject(vm, object);
		sq_pushstring(vm, name.c_str(), name.length());
		sqPushValue(vm, value);

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

		T get()
		{
			return getProperty<T>(object, propertyName);
		}

		void set(T value)
		{
			setProperty<T>(object, propertyName, value);
		}

	private:
		HSQOBJECT object;
		std::string propertyName;
	};
}
#endif
