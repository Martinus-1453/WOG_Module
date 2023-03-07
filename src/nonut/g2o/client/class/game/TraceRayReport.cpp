#include "TraceRayReport.h"

namespace nonut::g2o
{
	TraceRayReport::TraceRayReport(SQObject object) :
		Class("TraceRayReport", object),
		PROPERTY_CTOR(intersect),
		PROPERTY_CTOR(normal),
		PROPERTY_CTOR(vob)
	{
		if (object._type == OT_NULL)
		{
			isNullObj = true;
		}
	}
}
