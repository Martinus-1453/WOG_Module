#include "pch.h"
#include "ItemGround.h"
        
namespace nonut::g2o
{
	ItemGround::ItemGround(void) :
		Class("ItemGround"),
		METHOD_CTOR(getPosition),
		PROPERTY_CTOR(id),
		PROPERTY_CTOR(instance),
		PROPERTY_CTOR(amount),
		PROPERTY_CTOR(world),
		PROPERTY_CTOR(virtualWorld)
	{
		classCtor(void);
	}
}
