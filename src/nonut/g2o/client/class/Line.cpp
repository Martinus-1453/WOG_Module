#include "pch.h"
#include "Line.h"
        
namespace nonut::g2o
{
	Line::Line(Int x1, Int y1, Int x2, Int y2) :
		Class("Line"),
		METHOD_CTOR(top),
		METHOD_CTOR(setBegin),
		METHOD_CTOR(setEnd),
		METHOD_CTOR(setColor),
		METHOD_CTOR(getBegin),
		METHOD_CTOR(getEnd),
		METHOD_CTOR(getColor),
		PROPERTY_CTOR(visible)
	{
		classCtor(x1, y1, x2, y2);
	}
}
