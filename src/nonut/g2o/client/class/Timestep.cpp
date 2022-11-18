#include "pch.h"
#include "Timestep.h"
        
namespace nonut::g2o
{
	Timestep::Timestep() :
		Class("Timestep"),
		METHOD_CTOR(reset),
		METHOD_CTOR(update),
		PROPERTY_CTOR(factorMotion),
		PROPERTY_CTOR(frameTime),
		PROPERTY_CTOR(totalTime),
		PROPERTY_CTOR(frameTimeSecs),
		PROPERTY_CTOR(totalTimeSecs)
	{
		classCtor();
	}
}
