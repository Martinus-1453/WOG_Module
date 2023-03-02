#include "Vec4.h"

nonut::g2o::Vec4::Vec4() : Vec4(SQ_NULL)
{
	classCtor();
}

nonut::g2o::Vec4::Vec4(Float value) : Vec4(SQ_NULL)
{
	classCtor(value);
}

nonut::g2o::Vec4::Vec4(Float x, Float y, Float z, Float w) : Vec4(SQ_NULL)
{
	classCtor(x, y, z, w);
}

nonut::g2o::Vec4::Vec4(SQObject object) :
	Class("Vec4", object),
	PROPERTY_CTOR(x),
	PROPERTY_CTOR(y),
	PROPERTY_CTOR(z),
	PROPERTY_CTOR(w),
	METHOD_CTOR(len),
	METHOD_CTOR(len2),
	METHOD_CTOR(lenApprox),
	METHOD_CTOR(normalize),
	METHOD_CTOR(normalizeSafe),
	METHOD_CTOR(normalizeApprox),
	METHOD_CTOR(set),
	METHOD_CTOR(isEqualEps),
	METHOD_CTOR(abs),
	METHOD_CTOR(swap),
	METHOD_CTOR(min),
	METHOD_CTOR(max),
	METHOD_CTOR(prod),
	METHOD_CTOR(dot),
	METHOD_CTOR(lerp)
{
}
