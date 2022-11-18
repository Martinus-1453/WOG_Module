#pragma once
#ifndef MOB_DOOR_H
#define MOB_DOOR_H
#include <string>

#include "nonut/core/MobLockable.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class MobDoor : public MobLockable
	{
	protected:
		// Inheritance Ctor
		MobDoor(constexpr const char* className);
	public:
		MobDoor(std::string model);
		MobDoor(SQUserPointer ptr);
	};
}
#endif
