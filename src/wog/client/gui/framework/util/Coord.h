#ifndef WOG_CLIENT_GUI_FRAMEWORK_UTIL_COORD_H
#define WOG_CLIENT_GUI_FRAMEWORK_UTIL_COORD_H

#include "CommonHeader.h"
#include "WogHeader.h"

namespace wog::gui
{
	enum class CoordType
	{
		Virtual,
		Pixel
	};

	class Coord
	{
	public:
		Coord();
		~Coord() = default;
		explicit Coord(Int x1, Int y1);
		explicit Coord(Float x1, Float y1);

		bool operator==(const Coord& rhs) const;
		Coord& operator=(const Coord& rhs) = default;
		Coord operator+(const Coord& rhs) const;
		Coord operator-(const Coord& rhs) const;
		Coord& operator+=(const Coord& rhs);
		Coord& operator-=(const Coord& rhs);

		[[nodiscard]] std::pair<Int, Int> getPx() const;
		void setPx(Int x1, Int y1);

		[[nodiscard]] std::pair<Float, Float> getVt() const;
		void setVt(Float x1, Float y1);
		void setVt(Int x1, Int y1);

		[[nodiscard]] std::pair<Int, Int> getVti() const;

		[[nodiscard]] CoordType getType() const;
		void setType(CoordType newType);

		void normalize();

		static Float convertIntVtToFloatVt(Int value);
		static Int convertFloatVtToIntVt(Float value);

	private:
		[[nodiscard]] Float capVirtual(Float value) const
		{
			value = std::max(value, MIN_VIRTUAL_RANGE_FLOAT);
			value = std::min(value, MAX_VIRTUAL_RANGE_FLOAT);
			return value;
		}

		[[nodiscard]] Int capVirtual(Int value) const
		{
			value = std::max(value, MIN_VIRTUAL_RANGE_INT);
			value = std::min(value, MAX_VIRTUAL_RANGE_INT);
			return value;
		}

		union ScreenCoord
		{
			Int pxValue;
			Float vtValue;
		};

		ScreenCoord x{};
		ScreenCoord y{};
		CoordType type;

		static constexpr Int MAX_VIRTUAL_RANGE_INT = 8192;
		static constexpr Int MIN_VIRTUAL_RANGE_INT = 0;
		static constexpr Float MAX_VIRTUAL_RANGE_FLOAT = 1.f;
		static constexpr Float MIN_VIRTUAL_RANGE_FLOAT = 0.f;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_UTIL_COORD_H
