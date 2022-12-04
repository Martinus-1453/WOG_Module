#include "Virt.h"

namespace nonut::g2o
{
	Virt::Virt(const Float value)
	{
		if (value < 0.f)
		{
			x = 0.f;
		}
		else if (value > 1.f)
		{
			x = 1.f;
		}
		else
		{
			x = value;
		}
	}

	Virt::Virt(const Int value)
	{
		Int temp;
		if (value <= MIN_RANGE)
		{
			temp = 0.f;
		}
		else if (value >= MAX_RANGE)
		{
			temp = 1.f;
		}
		else
		{
			temp = value;
		}

		x = static_cast<Float>(temp) / static_cast<Float>(MAX_RANGE);
	}

	Virt::operator Int() const
	{
		auto result = static_cast<Int>(x * static_cast<Float>(MAX_RANGE));
		return result > MAX_RANGE ? MAX_RANGE : result;
	}

	Virt::operator Float() const
	{
		return x;
	}
}
