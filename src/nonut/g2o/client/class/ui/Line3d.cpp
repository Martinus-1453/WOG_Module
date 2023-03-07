#include "pch.h"
#include "Line3d.h"

namespace nonut::g2o
{
	Line3d::Line3d(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2) :
		Class("Line3d"),
		METHOD_CTOR(top),
		METHOD_CTOR(setBegin),
		METHOD_CTOR(setEnd),
		METHOD_CTOR(setColor),
		METHOD_CTOR(getBegin),
		METHOD_CTOR(getEnd),
		METHOD_CTOR(getColor),
		PROPERTY_CTOR(visible)
	{
		classCtor(x1, y1, z1, x2, y2, z2);
	}
}
