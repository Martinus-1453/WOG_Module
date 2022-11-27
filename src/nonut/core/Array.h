#ifndef NONUT_CORE_ARRAY_H
#define NONUT_CORE_ARRAY_H
#include "pch.h"

#include "Utils.h"

using namespace SqModule;

namespace nonut
{
	class Array
	{
	public:
		explicit Array(SQObject object);
		~Array();

		[[nodiscard]] size_t size() const;

		template<typename T>
		T get(String index)
		{
			T result{};
			sq_pushobject(vm, object);
			sq_pushstring(vm, index.c_str(), index.length());

			if (SQ_FAILED(sq_get(vm, -2))) {
				sq_pop(vm, 1);
				return result;
			}
			if constexpr (std::is_same_v<T, String>)
			{
				const SQChar* intermediateResult = nullptr;
				sq_getstring(vm, -1, &intermediateResult);
				result = intermediateResult;
			}
			else
			{
				sqGetValue(vm, -1, &result);
			}

			sq_pop(vm, 2);
			return result;

		}
	private:
		SQObject object;
		size_t cachedSize;
	};
}
#endif // NONUT_CORE_ARRAY_H
