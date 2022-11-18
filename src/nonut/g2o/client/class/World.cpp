#include "pch.h"
#include "World.h"
        
namespace nonut::g2o
{
	World::World(std::string fileName) :
		Class("World"),
		METHOD_CTOR(searchVobByName),
		METHOD_CTOR(stop),
		METHOD_CTOR(isPlaying),
		PROPERTY_CTOR(fileName),
		PROPERTY_CTOR(name),
		//PROPERTY_CTOR(vobs),
		PROPERTY_CTOR(showWaynet),
		PROPERTY_CTOR(showZonesDebugInfo)
	{
		classCtor(fileName);
	}
}
