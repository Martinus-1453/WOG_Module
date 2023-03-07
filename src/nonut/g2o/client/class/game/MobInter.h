#ifndef NONUT_G2O_CLIENT_CLASS_MOB_INTER_H
#define NONUT_G2O_CLIENT_CLASS_MOB_INTER_H
#include <string>

#include "Mob.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobInter : public Mob
	{
	public:
		MobInter(const String& model);
		MobInter(SQUserPointer ptr);
		MobInter(SQObject object, const String& className = "MobInter");
		COPY_CTOR(MobInter);
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_MOB_INTER_H
