#ifndef WOG_CLIENT_GUI_FRAMEWORK_UTIL_RECTANGLE_H
#define WOG_CLIENT_GUI_FRAMEWORK_UTIL_RECTANGLE_H
#include "Coord.h"

namespace wog::gui
{
	class Rectangle
	{
	public:
		Rectangle() = default;
		Rectangle(Int x, Int y, Int w, Int h);
		Rectangle(Coord position, Coord size);
		[[nodiscard]] bool collide(Int xOther, Int yOther) const;
		[[nodiscard]] bool collide(const Coord& other) const;

		Coord position;
		Coord size;
	};
}
#endif // WOG_CLIENT_GUI_FRAMEWORK_UTIL_RECTANGLE_H
