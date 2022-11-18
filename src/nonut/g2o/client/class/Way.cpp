#include "pch.h"
#include "Way.h"
        
namespace nonut::g2o
{
	Way::Way(std::string fileName) :
		Class("Way"),
		//METHOD_CTOR(getWaypoints),
		METHOD_CTOR(getCountWaypoints),
		PROPERTY_CTOR(start),
		PROPERTY_CTOR(end)
	{
		classCtor(fileName);
	}
}
