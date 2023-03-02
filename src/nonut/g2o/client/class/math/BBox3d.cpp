#include "BBox3d.h"

namespace nonut::g2o
{
	BBox3d::BBox3d(SQObject object) :
	Class("BBox3d", object),
	PROPERTY_CTOR(mins),
	PROPERTY_CTOR(maxs),
	PROPERTY_CTOR(center),
	METHOD_CTOR(intersecting)
	{
	}
}
