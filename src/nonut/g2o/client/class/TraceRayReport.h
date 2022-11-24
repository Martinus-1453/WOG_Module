#pragma once
#ifndef TRACE_RAY_REPORT_H
#define TRACE_RAY_REPORT_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class TraceRayReport : public Class
	{
	public:
		TraceRayReport(String fileName);

		// Properties
		Property<Vec3> intersect;
		Property<Vec3> normal;

		// Read-only properties
		Property<SQUserData, true> vob;
	};
}
#endif
