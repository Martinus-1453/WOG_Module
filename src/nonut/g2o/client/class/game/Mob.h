#ifndef NONUT_G2O_CLIENT_CLASS_MOB_H
#define NONUT_G2O_CLIENT_CLASS_MOB_H
#include <string>

#include "Vob.h"

namespace nonut::g2o
{
	class Mob : public Vob
	{
	public:
		Mob(const String& model);
		Mob(SQUserPointer ptr);
		Mob(SQObject object, const String& className = "Mob");
		COPY_CTOR(Mob);

		// Properties
		Property<String> name;
		Property<Bool> focusOverride;

		// Read-only properties
		Property<String, true> scemeName;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_MOB_H
