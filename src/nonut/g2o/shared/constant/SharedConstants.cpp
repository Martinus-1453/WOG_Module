#include "SharedConstants.h"

#include "Constant.h"
#include "Property.h"

namespace nonut::g2o
{
	void SharedConstants::init()
	{
		SQObject constTable = getConstTable();

#define GET_CONST(constName) Property<Int> constName ## Prop(#constName, constTable); \
	(constName) = constName ## Prop.get()

		GET_CONST(UNRELIABLE);
		GET_CONST(UNRELIABLE_SEQUENCED);
		GET_CONST(RELIABLE);
		GET_CONST(RELIABLE_ORDERED);
		GET_CONST(RELIABLE_SEQUENCED);
	}
}
