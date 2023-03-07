#include "pch.h"
#include "Way.h"

namespace nonut::g2o
{
	Way::Way(String world, String startWp, String endWp) :
		Class("Way"),
		METHOD_CTOR(getWaypoints),
		METHOD_CTOR(getCountWaypoints),
		PROPERTY_CTOR(start),
		PROPERTY_CTOR(end)
	{
		classCtor(world, startWp, endWp);
	}
}
