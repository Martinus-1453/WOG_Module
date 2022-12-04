#ifndef NONUT_G2O_CLIENT_VIRT_H
#define NONUT_G2O_CLIENT_VIRT_H
#include "pch.h"

namespace nonut::g2o
{
	class Virt
	{
	public:
		Virt() = default;
		explicit Virt(Float value);
		explicit Virt(Int value);

		operator Int() const;
		explicit operator Float() const;

		static constexpr Int MAX_RANGE = 8192;
		static constexpr Int MIN_RANGE = 0;
	private:
		Float x = 0.f;
	};
}
#endif // NONUT_G2O_CLIENT_VIRT_H
