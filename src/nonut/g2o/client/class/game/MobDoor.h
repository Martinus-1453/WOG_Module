#ifndef NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
#define NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
#include <string>

#include "MobLockable.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobDoor : public MobLockable
	{
	public:
		MobDoor(const String& model);
		MobDoor(SQUserPointer ptr);
		MobDoor(SQObject object, const String& className = "MobDoor");
		COPY_CTOR(MobDoor);
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
