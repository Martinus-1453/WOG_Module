#include "MobDoor.h"

#include <utility>

namespace nonut::g2o
{
	MobDoor::MobDoor(const String& model) : MobDoor(SQ_NULL)
	{
		classCtor(model);
	}

	MobDoor::MobDoor(const SQUserPointer ptr) : MobDoor(SQ_NULL)
	{
		classCtor(ptr);
	}

	MobDoor::MobDoor(const SQObject object, const String& className) :
		MobLockable(object, className)
	{
	}
}
