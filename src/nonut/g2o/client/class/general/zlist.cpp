#include "zlist.h"

namespace nonut::g2o
{
	zlist::zlist() : zlist(SQ_NULL)
	{
		classCtor();
	}

	zlist::zlist(SQObject object) :
	Class("zlist", object),
	METHOD_CTOR(len),
	METHOD_CTOR(isIn),
	METHOD_CTOR(insert),
	METHOD_CTOR(remove)
	{
	}
}
