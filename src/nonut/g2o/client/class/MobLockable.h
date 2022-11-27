#ifndef NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
#define NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
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
#endif // NONUT_G2O_CLIENT_CLASS_MOB_LOCKABLE_H
