#pragma once
#ifndef MOB_LOCKABLE_H
#define MOB_LOCKABLE_H
#include <string>

#include "nonut/core/MobInter.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class MobLockable : public MobInter
	{
	protected:
		// Inheritance Ctor
		MobLockable(constexpr const char* className);
	public:
		MobLockable(std::string model);
		MobLockable(SQUserPointer ptr);

		// Properties
		Property<bool> locked;
		Property<std::string> keyInstance;
		Property<std::string> pickLockStr;
	};
}
#endif
