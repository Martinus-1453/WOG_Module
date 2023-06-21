#include "Canvas.h"

namespace wog::gui
{
	Canvas::Canvas()
	{
		Object::setSize(Coord{ 1.f, 1.f });
		Object::setCollision(false);
	}
}
