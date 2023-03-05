#ifndef NONUT_G2O_CLIENT_CLASS_WORLD_H
#define NONUT_G2O_CLIENT_CLASS_WORLD_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"
#include "TraceRayReport.h"
#include "../../../../../wog/server/db/User.h"
#include "class/general/zlist.h"

namespace nonut::g2o
{
	class World : public Class
	{
	public:
		World(SQObject object);

		// Methods
		Function<UserData, String> searchVobByName;
		//Function<Array<SQUserData>, String> searchVobListByName;
		Function<TraceRayReport, Vec3, Vec3, Int> traceRayFirstHit;

		// Properties
		Property<String> fileName;
		Property<String> name;
		Property<zlist<SQUserPointer>> vobs;
		Property<Bool> showWaynet;
		Property<Bool> showZonesDebugInfo;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_WORLD_H
