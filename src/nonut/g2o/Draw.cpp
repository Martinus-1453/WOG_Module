#include "pch.h"
#include "Draw.h"

#include "nonut/Function.h"

namespace nonut::g2o
{
	Draw::Draw(int x, int y, std::string text) :
		Class("Draw"),
		METHOD_CTOR(top),
		PROPERTY_CTOR(visible)
	{
		ClassCtor(x, y, std::move(text));
		visible.Set(true);
	}
}
