#ifndef NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
#define NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
#include <string>

#include "MobLockable.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobDoor : public MobLockable
	{
	protected:
		// Inheritance Ctor
		MobDoor(constexpr const char* className);
	public:
		MobDoor(String model);
		MobDoor(SQUserPointer ptr);
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_MOB_DOOR_H
