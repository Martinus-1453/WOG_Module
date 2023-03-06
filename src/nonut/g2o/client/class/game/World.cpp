#include "pch.h"
#include "World.h"

namespace nonut::g2o
{
	World* World::get()
	{
		if (instance == nullptr)
		{
			instance = new World();
		}
		return instance;
	}

	World::World() :
		StaticClass("GameWorld"),
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
