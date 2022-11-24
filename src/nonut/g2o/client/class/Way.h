#pragma once
#ifndef WAY_H
#define WAY_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Way : public Class
	{
	public:
		Way(String fileName);

		// Methods
		//Function<std::vector<String>> getWaypoints;
		Function<Int> getCountWaypoints;

		// Read-only properties
		Property<String, true> start;
		Property<String, true> end;
	};
}
#endif
