#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class World : public Class
	{
	public:
		World(String fileName);

		// Methods
		Function<SQUserData, String> searchVobByName;

		Function<void> stop;
		Function<Bool> isPlaying;

		// Properties
		Property<String> fileName;
		Property<String> name;
		//Property<zlistsort&> vobs;
		Property<Bool> showWaynet;
		Property<Bool> showZonesDebugInfo;
	};
}
#endif
