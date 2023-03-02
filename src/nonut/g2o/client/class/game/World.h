#ifndef NONUT_G2O_CLIENT_CLASS_WORLD_H
#define NONUT_G2O_CLIENT_CLASS_WORLD_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"
#include "class/general/zlist.h"

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
		Property<zlist> vobs;
		Property<Bool> showWaynet;
		Property<Bool> showZonesDebugInfo;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_WORLD_H
