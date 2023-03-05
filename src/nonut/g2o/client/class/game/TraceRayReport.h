#ifndef NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H
#define NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H

#include "Class.h"
#include "class/math/Vec3.h"

namespace nonut::g2o
{
	class TraceRayReport : public Class
	{
	public:
		TraceRayReport(SQObject object);
		COPY_CTOR(TraceRayReport);

		[[nodiscard]] bool isNull() const { return isNullObj; }

		// Properties
		Property<Vec3> intersect;
		Property<Vec3> normal;

		// Read-only properties
		Property<SQUserData, true> vob;

	private:
		bool isNullObj = false;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_TRACE_RAY_REPORT_H
