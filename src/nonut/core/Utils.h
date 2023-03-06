#ifndef NONUT_CORE_UTILS_H
#define NONUT_CORE_UTILS_H

#include "Instance.h"
#include "pch.h"
#include "UserData.h"

using namespace SqModule;

namespace nonut
{
	struct CustomType
	{
		virtual void convert(HSQOBJECT object) = 0;
	};

	template <typename T>
	void sqGetValue(SQVM* vm, SQInteger idx, T outPtr)
	{
		static_assert(
			std::is_same_v<T, Bool*> ||
			std::is_same_v<T, Int*> ||
			std::is_same_v<T, Float*> ||
			std::is_same_v<T, SQChar**> ||
			std::is_same_v<T, HSQOBJECT*> ||
			std::is_same_v<T, SQUserPointer*>,
			"Not supported return type");

		if constexpr (std::is_same_v<T, Bool*>)
			sq_getbool(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, Int*>)
			sq_getinteger(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, Float*>)
			sq_getfloat(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, SQChar**>)
			sq_getstring(vm, idx, outPtr);
		if constexpr (std::is_same_v<T, HSQOBJECT*>)
		{
			sq_getstackobj(vm, idx, outPtr);
			sq_addref(vm, outPtr);
		}
		if constexpr (std::is_same_v<T, SQUserPointer*>)
		{
			sq_getuserpointer(vm, idx, outPtr);
		}
	}

	template <typename T>
	void sqPushValue(SQVM* vm, T value)
	{
		static_assert(
			std::is_same_v<T, bool> ||
			std::is_same_v<T, Bool> ||
			std::is_same_v<T, Int> ||
			std::is_same_v<T, Float> ||
			std::is_same_v<T, const SQChar*> ||
			std::is_same_v<T, SQObject> ||
			std::is_same_v<T, String> ||
			std::is_same_v<T, String&> ||
			std::is_same_v<T, SQUserPointer> ||
			std::derived_from<T, Instance>,
			"Not supported return type");

		if constexpr (std::is_same_v<T, bool>)
			sq_pushbool(vm, value);
		if constexpr (std::is_same_v<T, Bool>)
			sq_pushbool(vm, value);
		if constexpr (std::is_same_v<T, Int>)
			sq_pushinteger(vm, value);
		if constexpr (std::is_same_v<T, Float>)
			sq_pushfloat(vm, value);
		if constexpr (std::is_same_v<T, SQChar*>)
			sq_pushstring(vm, value, -1);
		if constexpr (std::is_same_v<T, SQObject>)
			sq_pushobject(vm, value);
		if constexpr (std::is_same_v<T, String> || std::is_same_v<T, String&>)
			sq_pushstring(vm, value.c_str(), value.length());
		if constexpr (std::is_same_v<T, SQUserPointer>)
			sq_pushuserpointer(vm, value);
		if constexpr (std::derived_from<T, Instance>)
			sq_pushobject(vm, value.getInstance());
	}

	template <typename T>
	T returnVar()
	{
		static_assert(
			std::is_same_v<T, SQObject> ||
			std::is_same_v<T, Bool> ||
			std::is_same_v<T, Float> ||
			std::is_same_v<T, Int> ||
			std::is_same_v<T, String>,
			"Not supported return type");

			T result{};
			sqGetValue(vm, -1, &result);
			sq_pop(vm, 1); // pops result
			return result;
	}

	template <>
	inline String returnVar<String>()
	{
		const SQChar* result = "";
		sq_getstring(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return result;
	}
}
#endif // NONUT_CORE_UTILS_H
