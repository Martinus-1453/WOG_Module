#ifndef NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H
#define NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H

#include "Class.h"
#include "class/math/Vec3.h"

namespace nonut::g2o
{
	class TraceRayReport : public Class
	{
	public:
		TraceRayReport(const String& fileName);
		TraceRayReport(SQObject object);
		COPY_CTOR(TraceRayReport);

		// Properties
		Property<Vec3> intersect;
		Property<Vec3> normal;

		// Read-only properties
		Property<SQUserData, true> vob;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H
