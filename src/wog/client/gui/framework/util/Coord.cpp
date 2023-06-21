#include "Coord.h"

#include "function/ClientFunctions.h"

namespace wog::gui
{
	Coord::Coord() : Coord(0, 0)
	{
	}

	Coord::Coord(const Int x1, const Int y1) :
		x{ .pxValue = x1 },
		y{ .pxValue = y1 },
		type(CoordType::Pixel)
	{
	}

	Coord::Coord(const Float x1, const Float y1) :
		x{ .vtValue = x1 },
		y{ .vtValue = y1 },
		type(CoordType::Virtual)
	{
	}

	bool Coord::operator==(const Coord& rhs) const
	{
		auto [x1, y1] = this->getPx();
		auto [x2, y2] = rhs.getPx();

		return x1 == x2 && y1 == y2;
	}

	Coord Coord::operator+(const Coord& rhs) const
	{
		if (this->type == CoordType::Virtual)
		{
			auto [x1, y1] = this->getVt();
			auto [x2, y2] = rhs.getVt();
			return Coord(x1 + x2, y1 + y2);
		}

		auto [x1, y1] = this->getPx();
		auto [x2, y2] = rhs.getPx();
		return Coord(x1 + x2, y1 + y2);

	}

	Coord Coord::operator-(const Coord& rhs) const
	{
		if (this->type == CoordType::Virtual)
		{
			auto [x1, y1] = this->getVt();
			auto [x2, y2] = rhs.getVt();
			return Coord(x1 - x2, y1 - y2);
		}

		auto [x1, y1] = this->getPx();
		auto [x2, y2] = rhs.getPx();
		return Coord(x1 - x2, y1 - y2);
	}

	Coord& Coord::operator+=(const Coord& rhs)
	{
		if (this->type == CoordType::Virtual)
		{
			auto [x1, y1] = this->getVt();
			auto [x2, y2] = rhs.getVt();
			this->setVt(x1 + x2, y1 + y2);
		}
		else
		{
			auto [x1, y1] = this->getPx();
			auto [x2, y2] = rhs.getPx();
			this->setPx(x1 + x2, y1 + y2);
		}
		return *this;
	}

	Coord& Coord::operator-=(const Coord& rhs)
	{
		if (this->type == CoordType::Virtual)
		{
			auto [x1, y1] = this->getVt();
			auto [x2, y2] = rhs.getVt();
			this->setVt(x1 - x2, y1 - y2);
		}
		else
		{
			auto [x1, y1] = this->getPx();
			auto [x2, y2] = rhs.getPx();
			this->setPx(x1 - x2, y1 - y2);
		}
		return *this;
	}

	std::pair<Int, Int> Coord::getPx() const
	{
		if (type == CoordType::Pixel)
		{
			return { x.pxValue, y.pxValue };
		}

		return { C_F->nax(convertFloatVtToIntVt(x.vtValue)),
			C_F->nay(convertFloatVtToIntVt(y.vtValue)) };
	}

	void Coord::setPx(const Int x1, const Int y1)
	{
		if (type == CoordType::Pixel)
		{
			x.pxValue = x1;
			y.pxValue = y1;
		}
		else
		{
			x.vtValue = convertIntVtToFloatVt(C_F->anx(x1));
			y.vtValue = convertIntVtToFloatVt(C_F->any(y1));
		}
	}

	std::pair<Float, Float> Coord::getVt() const
	{
		if (type == CoordType::Virtual)
		{
			return { x.vtValue, y.vtValue };
		}

		return { convertIntVtToFloatVt(C_F->anx(x.pxValue)),
			convertIntVtToFloatVt(C_F->any(y.pxValue)) };
	}

	void Coord::setVt(const Float x1, const Float y1)
	{
		if (type == CoordType::Virtual)
		{
			x.vtValue = x1;
			y.vtValue = y1;
		}
		else
		{
			x.pxValue = C_F->nax(convertFloatVtToIntVt(x1));
			y.pxValue = C_F->nay(convertFloatVtToIntVt(y1));
		}
	}

	void Coord::setVt(const Int x1, const Int y1)
	{
		setVt(convertIntVtToFloatVt(x1), convertIntVtToFloatVt(y1));
	}

	std::pair<Int, Int> Coord::getVti() const
	{
		auto&& [x1, y1] = getVt();
		return { convertFloatVtToIntVt(x1), convertFloatVtToIntVt(y1) };
	}

	CoordType Coord::getType() const
	{
		return type;
	}

	void Coord::setType(const CoordType newType)
	{
		if (type == newType) return;

		type = newType;

		// Pixel to Virtual
		if (newType == CoordType::Virtual)
		{
			auto [x1, y1] = getVt();
			x.vtValue = x1;
			y.vtValue = y1;
			return;
		}

		// Virtual to Pixel
		auto [x1, y1] = getPx();
		x.pxValue = x1;
		y.pxValue = y1;
	}

	void Coord::normalize()
	{
		if (type == CoordType::Virtual)
		{
			x.vtValue = capVirtual(x.vtValue);
			y.vtValue = capVirtual(y.vtValue);
		}
	}

	Float Coord::convertIntVtToFloatVt(const Int value)
	{
		//if (value <= MIN_RANGE) return 0.f;
		//if (value >= MAX_RANGE) return 1.f;
		return static_cast<Float>(value) / static_cast<Float>(MAX_VIRTUAL_RANGE_INT);
	}
	Int Coord::convertFloatVtToIntVt(const Float value)
	{
		//if (value <= 0.f) return MIN_RANGE;
		//if (value >= 1.f) return MAX_RANGE;
		return static_cast<Int>(value * static_cast<Float>(MAX_VIRTUAL_RANGE_INT));
	}
}
