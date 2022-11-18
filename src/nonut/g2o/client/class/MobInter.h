#pragma once
#ifndef MOB_INTER_H
#define MOB_INTER_H
#include <string>

#include "nonut/core/Mob.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class MobInter : public Mob
	{
	protected:
		// Inheritance Ctor
		MobInter(constexpr const char* className);
	public:
		MobInter(std::string model);
		MobInter(SQUserPointer ptr);
	};
}
#endif
