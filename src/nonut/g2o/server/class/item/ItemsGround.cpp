#include "pch.h"
#include "ItemsGround.h"

namespace nonut::g2o
{
	ItemsGround::ItemsGround(SQObject object) :
		Class("ItemsGround"),
		METHOD_CTOR(id),
		METHOD_CTOR(spawn),
		METHOD_CTOR(destroy)
	{
		classCtor(object);
	}
}
