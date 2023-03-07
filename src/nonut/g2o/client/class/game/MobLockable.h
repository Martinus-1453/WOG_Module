#ifndef NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
#define NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
#include <string>

#include "MobInter.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class MobLockable : public MobInter
	{
	public:
		MobLockable(const String& model);
		MobLockable(SQUserPointer ptr);
		MobLockable(SQObject object, const String& className = "MobLockable");
		COPY_CTOR(MobLockable);

		// Properties
		Property<Bool> locked;
		Property<String> keyInstance;
		Property<String> pickLockStr;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
