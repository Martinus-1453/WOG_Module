#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <vector>

#include "pch.h"
#include "Utils.h"

using namespace SqModule;

namespace nonut
{
	class Array
	{
	public:
		explicit Array(HSQOBJECT object);
		~Array();

		[[nodiscard]] size_t size() const;

		template<typename T>
		T get(std::string index)
		{
			T result{};
			sq_pushobject(vm, object);
			sq_pushstring(vm, index.c_str(), index.length());

			if (SQ_FAILED(sq_get(vm, -2))) {
				sq_pop(vm, 1);
				return result;
			}
			if constexpr (std::is_same_v<T, std::string>)
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
		HSQOBJECT object;
		size_t cachedSize;
	};
}
#endif