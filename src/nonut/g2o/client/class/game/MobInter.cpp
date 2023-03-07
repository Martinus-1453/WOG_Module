#include "MobInter.h"

#include <utility>

namespace nonut::g2o
{
	MobInter::MobInter(const String& model) : MobInter(SQ_NULL)
	{
		classCtor(model);
	}
	MobInter::MobInter(const SQUserPointer ptr) : MobInter(SQ_NULL)
	{
		classCtor(ptr);
	}
	MobInter::MobInter(const SQObject object, const String& className) :
		Mob(object, className)
	{
	}
}
