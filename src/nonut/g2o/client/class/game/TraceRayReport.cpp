#include "TraceRayReport.h"

namespace nonut::g2o
{
	TraceRayReport::TraceRayReport(const String& fileName) : TraceRayReport(SQ_NULL)
	{
		classCtor(fileName);
	}

	TraceRayReport::TraceRayReport(SQObject object) :
		Class("TraceRayReport"),
		PROPERTY_CTOR(intersect),
		PROPERTY_CTOR(normal),
		PROPERTY_CTOR(vob)
	{
	}
}
