#include "MobLockable.h"

#include <utility>

namespace nonut::g2o
{
	MobLockable::MobLockable(const String& model) : MobLockable(SQ_NULL)
	{
		classCtor(model);
	}
	MobLockable::MobLockable(const SQUserPointer ptr) : MobLockable(SQ_NULL)
	{
		classCtor(ptr);
	}
	MobLockable::MobLockable(const SQObject object, const String& className) :
		MobInter(object, className),
		PROPERTY_CTOR(locked),
		PROPERTY_CTOR(keyInstance),
		PROPERTY_CTOR(pickLockStr)
	{
	}
}
