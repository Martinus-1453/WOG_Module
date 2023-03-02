#include "Draw3d.h"

namespace nonut::g2o
{
	Draw3d::Draw3d(Float x, Float y, Float z) :
		Class("Draw3d"),
		METHOD_CTOR(top),
		METHOD_CTOR(setLineFont),
		METHOD_CTOR(getLineFont),
		METHOD_CTOR(setColor),
		METHOD_CTOR(getColor),
		METHOD_CTOR(setLineColor),
		METHOD_CTOR(getLineColor),
		METHOD_CTOR(setLineAlpha),
		METHOD_CTOR(getLineAlpha),
		METHOD_CTOR(insertText),
		METHOD_CTOR(removeText),
		METHOD_CTOR(getText),
		METHOD_CTOR(setLineText),
		METHOD_CTOR(getLineText),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(setPositionPx),
		METHOD_CTOR(getPositionPx),
		METHOD_CTOR(setWorldPosition),
		METHOD_CTOR(getWorldPosition),
		PROPERTY_CTOR(visible),
		PROPERTY_CTOR(font),
		PROPERTY_CTOR(alpha),
		PROPERTY_CTOR(distance),
		PROPERTY_CTOR(width),
		PROPERTY_CTOR(widthPx),
		PROPERTY_CTOR(height),
		PROPERTY_CTOR(heightPx)
	{
		classCtor(x, y, z);
	}
}
