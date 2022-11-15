#include "Constant.h"

using namespace SqModule;

namespace nonut
{
	HSQOBJECT GetConstTable()
	{
		HSQOBJECT obj;
		sq_pushconsttable(vm);
		sq_getstackobj(vm, -1, &obj);
		sq_pop(vm, 1); // No addref needed, since the consttable is always around
		return obj;
	}
}
