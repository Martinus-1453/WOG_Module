#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

#include "squirrel_api.h"
#include "module_api.h"
#include "Utils.h"

#define FUNCTION_CTOR(function) function(#function)

using namespace SqModule;

namespace nonut
{
	template <typename ReturnType, typename... Args>
	class Function
	{
	public:
		// Ctor for functions
		Function(const std::string& functionName, const HSQOBJECT env = getRootTable()) : envObj(env)
		{
			sq_pushobject(vm, envObj);
			sq_pushstring(vm, functionName.c_str(), functionName.length());

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
		Function(const std::string& functionName, const HSQOBJECT classObjectInstance,
		         const HSQOBJECT classObject) : envObj(classObjectInstance)
		{
			isClassMethod = true; // Prevent release of the resources cause we don't own them
			sq_pushobject(vm, classObject);
			sq_pushstring(vm, functionName.c_str(), functionName.length());

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

			(sqPushValue(vm, args), ...);

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

				ReturnType result{};

				if constexpr (std::derived_from<ReturnType, CustomType>)
				{
					HSQOBJECT intermediateResult = returnVar<HSQOBJECT>();
					result.convert(intermediateResult);
					sq_release(vm, &intermediateResult);
					sq_resetobject(&intermediateResult);
				}
				else
				{
					result = returnVar<ReturnType>();
				}
				
				sq_pop(vm, 2);
				sq_settop(vm, top); // TODO: FIX LEAK PROPERLY
				return result;
			}
		}

		[[nodiscard]] HSQOBJECT getObject() const
		{
			return funcObj;
		}

	private:
		HSQOBJECT funcObj{};
		HSQOBJECT envObj{};
		bool isClassMethod = false;
		static constexpr auto argCount{sizeof...(Args)};

		static HSQOBJECT getRootTable()
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
