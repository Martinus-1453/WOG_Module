#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <string>

#include "nonut/core/Class.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class World : public Class
	{
	public:
		World(std::string fileName);

		// Methods
		Function<SQUserData, std::string> searchVobByName;

		Function<void> stop;
		Function<bool> isPlaying;

		// Properties
		Property<std::string> fileName;
		Property<std::string> name;
		//Property<zlistsort&> vobs;
		Property<bool> showWaynet;
		Property<bool> showZonesDebugInfo;
	};
}
#endif
