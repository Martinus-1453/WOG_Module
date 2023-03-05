#include "pch.h"
#include "World.h"

namespace nonut::g2o
{
	World::World(SQObject object) :
		Class("World", object),
		METHOD_CTOR(searchVobByName),
		METHOD_CTOR(traceRayFirstHit),
		PROPERTY_CTOR(fileName),
		PROPERTY_CTOR(name),
		PROPERTY_CTOR(vobs),
		PROPERTY_CTOR(showWaynet),
		PROPERTY_CTOR(showZonesDebugInfo)
	{
	}
}
