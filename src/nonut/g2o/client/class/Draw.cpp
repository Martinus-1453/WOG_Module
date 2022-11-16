#include "pch.h"
#include "Draw.h"

#include "nonut/core/Function.h"

namespace nonut::g2o
{
	Draw::Draw(int x, int y, std::string text) :
		Class("Draw"),
		METHOD_CTOR(top),
		PROPERTY_CTOR(visible)
	{
		classCtor(x, y, std::move(text));
		visible.set(true);
	}
}
