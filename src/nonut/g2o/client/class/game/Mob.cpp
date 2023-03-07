#include "Mob.h"

namespace nonut::g2o
{
	Mob::Mob(const String& model) : Mob(SQ_NULL)
	{
		classCtor(model);
	}
	Mob::Mob(const SQUserPointer ptr) : Mob(SQ_NULL)
	{
		classCtor(ptr);
	}
	Mob::Mob(const SQObject object, const String& className) :
		Vob(object, className),
		PROPERTY_CTOR(name),
		PROPERTY_CTOR(focusOverride),
		PROPERTY_CTOR(scemeName)
	{
	}
}
