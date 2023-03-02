#ifndef NONUT_CORE_FUNCTION_H
#define NONUT_CORE_FUNCTION_H

#include <optional>
#include <string>

#include "squirrel_api.h"
#include "module_api.h"
#include "Utils.h"

#define FUNCTION_CTOR(function) function(#function)

using namespace SqModule;

namespace nonut
{
	class Class;

	template <typename ReturnType, typename... Args>
	class Function
	{
	public:
		// Ctor for functions
		Function(const String& functionName, const SQObject env = getRootTable()) : envObj(env)
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
		Function(const String& functionName, const SQObject classObjectInstance,
		         const SQObject classObject) : envObj(classObjectInstance)
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
			const auto top = sq_gettop(vm);
			sq_pushobject(vm, funcObj);
			sq_pushobject(vm, envObj);
			auto debug = sq_gettop(vm);
			(sqPushValue(vm, args), ...);
			
			if constexpr (std::is_same_v<ReturnType, void>)
			{
				debug = sq_gettop(vm);
				auto returnCode = sq_call(vm, ARG_COUNT + 1, SQFalse, SQFalse); // TODO: HANDLE ERROR RETURN CODE
				sq_pop(vm, 2);
				sq_settop(vm, top);
				return void();
			}
			else
			{
				auto returnCode = sq_call(vm, ARG_COUNT + 1, SQTrue, SQFalse); // TODO: HANDLE ERROR RETURN CODE

				std::optional<ReturnType> result;

				if constexpr (std::derived_from<ReturnType, CustomType>)
				{
					result = std::make_optional<ReturnType>();
					auto intermediateResult = returnVar<SQObject>();
					result.value().convert(intermediateResult);
					sq_release(vm, &intermediateResult);
					sq_resetobject(&intermediateResult);
				}
				else if constexpr (std::derived_from<ReturnType, Class>)
				{
					auto intermediateResult = returnVar<SQObject>();
					//result = std::make_optional<ReturnType>(ReturnType(intermediateResult));
					result.emplace(ReturnType(intermediateResult));
					
					sq_release(vm, &intermediateResult);
					sq_resetobject(&intermediateResult);
				}
				else
				{
					result = std::make_optional<ReturnType>(returnVar<ReturnType>());
				}
				
				sq_pop(vm, 2);
				sq_settop(vm, top);
				return result.value();
			}
		}

		[[nodiscard]] SQObject getObject() const
		{
			return funcObj;
		}

	private:
		SQObject funcObj{};
		SQObject envObj{};
		bool isClassMethod = false;
		static constexpr auto ARG_COUNT{sizeof...(Args)};

		static SQObject getRootTable()
		{
			SQObject rootTable{};
			sq_pushroottable(vm);
			sq_getstackobj(vm, -1, &rootTable);
			sq_addref(vm, &rootTable);
			sq_pop(vm, 1); // pop root table
			return rootTable;
		}
	};
}
#endif // NONUT_CORE_FUNCTION_H
