#include "pch.h"
#include "Array.h"

using namespace SqModule;

namespace nonut
{
	Array::Array(SQObject object) : object(object), cachedSize(size())
	{
	}

	Array::~Array() = default;

	size_t Array::size() const
	{
		sq_pushobject(vm, object);
		const auto result = sq_getsize(vm, -1);
		sq_pop(vm, 1);
		return static_cast<size_t>(result);
	}
}
