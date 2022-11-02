#pragma once
#include <string>
#include <type_traits>

#include "api/squirrel_api.h"
#include "api/module_api.h"

using namespace SqModule;

namespace nonut {

	template <typename ReturnType, typename... Args>
	class Function
	{
	public:
		Function(std::string _functionName)
		{
			(Count(_args), ...);

			sq_pushroottable(vm);
			sq_pushstring(vm, _functionName.c_str(), _functionName.length());
			sq_get(vm, -2); //get the function from the root table

			if (SQ_FAILED(sq_get(vm, -2)))
			{
				sq_pop(vm, 1);
				throw;
			}
			SQObjectType value_type = sq_gettype(vm, -1);
			if (value_type != OT_CLOSURE && value_type != OT_NATIVECLOSURE)
			{
				sq_pop(vm, 2);
				throw;
			}

			sq_getstackobj(vm, -1, &funcObj);
			sq_addref(vm, &funcObj);

			sq_pop(vm, 2);
		}

		~Function()
		{
			sq_release(vm, &funcObj);
			sq_resetobject(&funcObj);
		}

		ReturnType operator()(Args... _args)
		{
			SQInteger top = sq_gettop(vm);

			sq_pushobject(vm, funcObj);
			sq_pushroottable(vm);

			(PushArg(_args), ...);

			if constexpr (std::is_same<ReturnType, void>)
			{
				sq_call(v, count + 1, SQFalse, SQFalse);
			}
			else
			{
				sq_call(v, count + 1, SQTrue, SQFalse);
			}
		}

	protected:


	private:
		HSQOBJECT funcObj;
		size_t count = 0;

		template<typename T>
		constexpr void Count(T t)
		{
			++count;
		}

		template <typename T>
		void PushArg(T value)
		{
			static_assert(false, "Not supported argument type");
		}

		template<>
		void PushArg<bool>(bool value)
		{
			sq_pushbool(vm, value);
		}

		template<>
		void PushArg<float>(float value)
		{
			sq_pushfloat(vm, value);
		}

		template<>
		void PushArg<int>(int value)
		{
			sq_pushinteger(vm, value);
		}

		template<>
		void PushArg<>(std::string value)
		{
			sq_pushstring(vm, value.c_str(), value.length());
		}
	};
}