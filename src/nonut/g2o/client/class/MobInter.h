#pragma once
#ifndef MOB_INTER_H
#define MOB_INTER_H
#include <string>

#include "Mob.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobInter : public Mob
	{
	protected:
		// Inheritance Ctor
		MobInter(constexpr const char* className);
	public:
		MobInter(String model);
		MobInter(SQUserPointer ptr);
	};
}
#endif
