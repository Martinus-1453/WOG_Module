#pragma once
#ifndef MOB_LOCKABLE_H
#define MOB_LOCKABLE_H
#include <string>

#include "MobInter.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobLockable : public MobInter
	{
	protected:
		// Inheritance Ctor
		MobLockable(constexpr const char* className);
	public:
		MobLockable(String model);
		MobLockable(SQUserPointer ptr);

		// Properties
		Property<Bool> locked;
		Property<String> keyInstance;
		Property<String> pickLockStr;
	};
}
#endif
