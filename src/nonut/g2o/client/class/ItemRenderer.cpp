#include "pch.h"
#include "ItemRenderer.h"
        
namespace nonut::g2o
{
	ItemRenderer::ItemRenderer(int x, int y, int width, int height, std::string instance) :
		Class("ItemRenderer"),
		METHOD_CTOR(top),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(setPositionPx),
		METHOD_CTOR(setSize),
		METHOD_CTOR(setSizePx),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(getPositionPx),
		METHOD_CTOR(getSize),
		METHOD_CTOR(getSizePx),
		PROPERTY_CTOR(visible),
		PROPERTY_CTOR(rotX),
		PROPERTY_CTOR(rotY),
		PROPERTY_CTOR(rotZ),
		PROPERTY_CTOR(zbias),
		PROPERTY_CTOR(lightingswell),
		PROPERTY_CTOR(visual),
		PROPERTY_CTOR(instance)
	{
		classCtor(x, y, width, height, instance);
	}
}
