#include "pch.h"
#include "Texture.h"

namespace nonut::g2o
{
	Texture::Texture(Int x, Int y, Int width, Int height, String txt) :
		Class("Texture"),
		METHOD_CTOR(top),
		METHOD_CTOR(setColor),
		METHOD_CTOR(getColor),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(setPositionPx),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(getPositionPx),
		METHOD_CTOR(setPivotPoint),
		METHOD_CTOR(setPivotPointPx),
		METHOD_CTOR(getPivotPoint),
		METHOD_CTOR(getPivotPointPx),
		METHOD_CTOR(setSize),
		METHOD_CTOR(setSizePx),
		METHOD_CTOR(getSize),
		METHOD_CTOR(getSizePx),
		METHOD_CTOR(setRect),
		METHOD_CTOR(setRectPx),
		METHOD_CTOR(getRect),
		METHOD_CTOR(getRectPx),
		METHOD_CTOR(setUV),
		METHOD_CTOR(getUV),
		PROPERTY_CTOR(visible),
		PROPERTY_CTOR(file),
		PROPERTY_CTOR(alpha),
		PROPERTY_CTOR(rotation)
	{
		classCtor(x, y, width, height, txt);
	}
}
