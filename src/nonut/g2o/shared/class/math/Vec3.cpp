#include "Vec3.h"

namespace nonut::g2o
{

	Vec3::Vec3() : Vec3(SQ_NULL)
	{
		classCtor();
	}

	Vec3::Vec3(Float value) : Vec3(SQ_NULL)
	{
		classCtor(value);
	}

	Vec3::Vec3(Float x, Float y, Float z) : Vec3(SQ_NULL)
	{
		classCtor(x, y, z);
	}

	Vec3::Vec3(SQObject object) : 
		Class("Vec3", object),
		PROPERTY_CTOR(x),
		PROPERTY_CTOR(y),
		PROPERTY_CTOR(z),
		METHOD_CTOR(len),
		METHOD_CTOR(len2),
		METHOD_CTOR(lenApprox),
		METHOD_CTOR(distance),
		METHOD_CTOR(normalize),
		METHOD_CTOR(normalizeSafe),
		METHOD_CTOR(normalizeApprox),
		METHOD_CTOR(set),
		METHOD_CTOR(isEqualEps),
		METHOD_CTOR(abs),
		METHOD_CTOR(reflect),
		METHOD_CTOR(swap),
		METHOD_CTOR(min),
		METHOD_CTOR(max),
		METHOD_CTOR(prod),
		METHOD_CTOR(dot),
		METHOD_CTOR(cross),
		METHOD_CTOR(lerp)
	{
	}
}
