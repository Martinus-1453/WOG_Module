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
		Way(std::string fileName);

		// Methods
		//Function<std::vector<std::string>> getWaypoints;
		Function<int> getCountWaypoints;

		// Read-only properties
		Property<std::string, true> start;
		Property<std::string, true> end;
	};
}
#endif
