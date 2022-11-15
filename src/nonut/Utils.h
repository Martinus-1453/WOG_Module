#pragma once

#ifndef UTILS_H
#define UTILS_H
#include "pch.h"

using namespace SqModule;

namespace nonut
{
	template <typename T>
	void sqGetValue(HSQUIRRELVM vm, SQInteger idx, T outPtr)
	{
		static_assert(
			std::is_same_v<T, SQBool*> ||
			std::is_same_v<T, SQInteger*> ||
			std::is_same_v<T, SQFloat*> ||
			std::is_same_v<T, SQChar**> ||
			std::is_same_v<T, HSQOBJECT*>,
			"Not supported return type");

		if constexpr (std::is_same_v<T, SQBool*>)
			sq_getbool(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, SQInteger*>)
			sq_getinteger(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, SQFloat*>)
			sq_getfloat(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, SQChar**>)
			sq_getstring(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, HSQOBJECT*>)
			sq_getstackobj(vm, idx, outPtr);
	}

	template <typename T>
	void sqPushValue(HSQUIRRELVM vm, T value)
	{
		static_assert(
			std::is_same_v<T, bool> ||
			std::is_same_v<T, SQBool> ||
			std::is_same_v<T, SQInteger> ||
			std::is_same_v<T, SQFloat> ||
			std::is_same_v<T, SQChar*> ||
			std::is_same_v<T, HSQOBJECT> ||
			std::is_same_v<T, std::string>,
			"Not supported return type");

		if constexpr (std::is_same_v<T, bool>)
			sq_pushbool(vm, value);
		if constexpr (std::is_same_v<T, SQBool>)
			sq_pushbool(vm, value);
		if constexpr (std::is_same_v<T, SQInteger>)
			sq_pushinteger(vm, value);
		if constexpr (std::is_same_v<T, SQFloat>)
			sq_pushfloat(vm, value);
		if constexpr (std::is_same_v<T, SQChar*>)
			sq_pushstring(vm, value, -1);
		if constexpr (std::is_same_v<T, HSQOBJECT>)
			sq_pushobject(vm, value);
		if constexpr (std::is_same_v<T, std::string>)
			sq_pushstring(vm, value.c_str(), value.length());
	}

	template <typename T>
	T returnVar()
	{
		static_assert(
			std::is_same_v<T, HSQOBJECT> ||
			std::is_same_v<T, bool> ||
			std::is_same_v<T, float> ||
			std::is_same_v<T, int> ||
			std::is_same_v<T, std::string>,
			"Not supported return type");
		T result;
		sq_getvalue(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return result;
	}

	template <>
	inline std::string returnVar<std::string>()
	{
		const SQChar* result = nullptr;
		sq_getstring(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return std::string(result);
	}
}
#endif
