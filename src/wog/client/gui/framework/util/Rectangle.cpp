#include "Rectangle.h"

namespace wog::gui
{
	Rectangle::Rectangle(const Int x, const Int y, const Int w, const Int h) : position(x, y), size(w, h)
	{
	}

	Rectangle::Rectangle(const Coord position, const Coord size) : position(position), size(size)
	{
	}

	bool Rectangle::collide(const Int xOther, const Int yOther) const
	{
		auto&& [x, y] = position.getPx();
		auto&& [width, height] = size.getPx();
		return xOther >= x &&
			xOther <= x + width &&
			yOther >= y &&
			yOther <= y + height;
	}

	bool Rectangle::collide(const Coord& other) const
	{
		auto&& [x, y] = other.getPx();
		return collide(x, y);
	}
}
