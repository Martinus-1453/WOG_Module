#ifndef NONUT_CORE_STRINGIFY_H
#define NONUT_CORE_STRINGIFY_H

#include "pch.h"

namespace nonut
{
	template <typename T>
	class Stringify
	{
	public:
		virtual ~Stringify() = default;

		[[nodiscard]] virtual String toString() const
		{
			return STRINGIFY(T);
		}
	};
}
#endif //NONUT_CORE_STRINGIFY_H
