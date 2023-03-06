#ifndef NONUT_G2O_CLIENT_CLASS_WORLD_H
#define NONUT_G2O_CLIENT_CLASS_WORLD_H
#include <string>

#include "Class.h"
#include "StaticClass.h"
#include "TraceRayReport.h"
#include "class/general/zlist.h"

namespace nonut::g2o
{
	class World : public StaticClass
	{
	public:
		static World* get();

		// Methods
		Function<SQUserPointer, String> searchVobByName;
		//Function<Array<SQUserData>, String> searchVobListByName;
		Function<TraceRayReport, Vec3, Vec3, Int> traceRayFirstHit;

		// Properties
		Property<String> fileName;
		Property<String> name;
		Property<zlist<SQUserPointer>> vobs;
		Property<Bool> showWaynet;
		Property<Bool> showZonesDebugInfo;

	private:
		static inline World* instance = nullptr;

		World();
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_WORLD_H
