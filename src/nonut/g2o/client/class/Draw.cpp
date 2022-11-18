#include "pch.h"
#include "Draw.h"

namespace nonut::g2o
{
	Draw::Draw(int x, int y, std::string text) :
		Class("Draw"),
		METHOD_CTOR(top),
		METHOD_CTOR(setColor),
		METHOD_CTOR(getColor),
		METHOD_CTOR(setScale),
		METHOD_CTOR(getScale),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(setPositionPx),
		METHOD_CTOR(getPositionPx),
		METHOD_CTOR(setPivotPoint),
		METHOD_CTOR(setPivotPointPx),
		METHOD_CTOR(getPivotPoint),
		METHOD_CTOR(getPivotPointPx),
		PROPERTY_CTOR(visible),
		PROPERTY_CTOR(text),
		PROPERTY_CTOR(font),
		PROPERTY_CTOR(alpha),
		PROPERTY_CTOR(rotation),
		PROPERTY_CTOR(width),
		PROPERTY_CTOR(widthPx),
		PROPERTY_CTOR(height),
		PROPERTY_CTOR(heightPx)
	{
		classCtor(x, y, std::move(text));
	}
}
