#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

#include "api/squirrel_api.h"
#include "api/module_api.h"

using namespace SqModule;

namespace nonut
{
	inline class PushArg
	{
	} pushArgObject;

	inline PushArg operator<<(const PushArg pushArg, bool value)
	{
		sq_pushbool(vm, value);
		return pushArg;
	}

	inline PushArg operator<<(const PushArg pushArg, float value)
	{
		sq_pushfloat(vm, value);
		return pushArg;
	}

	inline PushArg operator<<(const PushArg pushArg, int value)
	{
		sq_pushinteger(vm, value);
		return pushArg;
	}

	inline PushArg operator<<(const PushArg pushArg, const std::string& value)
	{
		sq_pushstring(vm, value.c_str(), value.length());
		return pushArg;
	}

	inline PushArg operator<<(const PushArg pushArg, HSQOBJECT value)
	{
		sq_pushobject(vm, value);
		return pushArg;
	}


	template <typename T>
	T ReturnVar()
	{
		static_assert(
			std::is_same_v<T, HSQOBJECT> ||
			std::is_same_v<T, bool> ||
			std::is_same_v<T, float> ||
			std::is_same_v<T, int> ||
			std::is_same_v<T, std::string>,
			"Not supported return type");

		return T();
	}

	template <>
	inline HSQOBJECT ReturnVar<HSQOBJECT>()
	{
		HSQOBJECT result;
		sq_getstackobj(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return result;
	}

	template <>
	inline bool ReturnVar<bool>()
	{
		SQBool result;
		sq_getbool(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return static_cast<bool>(result);
	}

	template <>
	inline float ReturnVar<float>()
	{
		float result;
		sq_getfloat(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return result;
	}

	template <>
	inline int ReturnVar<int>()
	{
		int result;
		sq_getinteger(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return result;
	}

	template <>
	inline std::string ReturnVar<std::string>()
	{
		const SQChar* result = nullptr;
		sq_getstring(vm, -1, &result);
		sq_pop(vm, 1); // pops result
		return std::string(result);
	}


	template <typename ReturnType, typename... Args>
	class Function
	{
	public:
		// Ctor for functions
		Function(const std::string& _functionName, const HSQOBJECT env = GetRootTable()) : envObj(env)
		{
			sq_pushobject(vm, envObj);
			sq_pushstring(vm, _functionName.c_str(), _functionName.length());

			// get the function from the root table
			if (SQ_FAILED(sq_get(vm, -2)))
			{
				sq_pop(vm, 1);
				throw;
			}

			// check the type
			if (const SQObjectType value_type = sq_gettype(vm, -1); value_type != OT_CLOSURE && value_type !=
				OT_NATIVECLOSURE)
			{
				sq_pop(vm, 2);
				throw;
			}

			// get function and add ref
			sq_getstackobj(vm, -1, &funcObj);
			sq_addref(vm, &funcObj);

			sq_pop(vm, 2);
		}

		// Ctor for class methods
		Function(const std::string& _functionName, const HSQOBJECT classObjectInstance,
		         const HSQOBJECT classObject) : envObj(classObjectInstance)
		{
			isClassMethod = true;
			sq_pushobject(vm, classObject);
			sq_pushstring(vm, _functionName.c_str(), _functionName.length());

			// get the function from the root table
			if (SQ_FAILED(sq_get(vm, -2)))
			{
				sq_pop(vm, 1);
				throw;
			}

			// check the type
			if (const SQObjectType value_type = sq_gettype(vm, -1); value_type != OT_CLOSURE && value_type !=
				OT_NATIVECLOSURE)
			{
				sq_pop(vm, 2);
				throw;
			}

			// get function and add ref
			sq_getstackobj(vm, -1, &funcObj);
			sq_addref(vm, &funcObj);

			sq_pop(vm, 2);
		}

		~Function()
		{
			if (!isClassMethod)
			{
				sq_release(vm, &funcObj);
				sq_release(vm, &envObj);
				sq_resetobject(&funcObj);
				sq_resetobject(&envObj);
			}
		}

		ReturnType operator()(Args ... args)
		{
			const SQInteger top = sq_gettop(vm);
			sq_pushobject(vm, funcObj);
			sq_pushobject(vm, envObj);

			((pushArgObject << args), ...);

			if constexpr (std::is_same_v<ReturnType, void>)
			{
				auto returnCode = sq_call(vm, argCount + 1, SQFalse, SQFalse); // TODO: HANDLE ERROR RETURN CODE
				sq_pop(vm, 2);
				sq_settop(vm, top); // TODO: FIX LEAK PROPERLY
				return void();
			}
			else
			{
				auto returnCode = sq_call(vm, argCount + 1, SQTrue, SQFalse); // TODO: HANDLE ERROR RETURN CODE
				auto result = ReturnVar<ReturnType>();
				sq_pop(vm, 2);
				sq_settop(vm, top); // TODO: FIX LEAK PROPERLY
				return result;
			}
		}

		HSQOBJECT GetObject()
		{
			return funcObj;
		}

	private:
		HSQOBJECT funcObj{};
		HSQOBJECT envObj{};
		bool isClassMethod = false;
		static constexpr auto argCount{sizeof...(Args)};

		static HSQOBJECT GetRootTable()
		{
			HSQOBJECT rootTable{};
			sq_pushroottable(vm);
			sq_getstackobj(vm, -1, &rootTable);
			sq_addref(vm, &rootTable);
			sq_pop(vm, 1); // pop root table
			return rootTable;
		}
	};
}
#endif // FUNCTION_H
