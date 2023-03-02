#include "Mat4.h"

namespace nonut::g2o
{
	Mat4::Mat4() : Mat4(SQ_NULL)
	{
		classCtor();
	}

	Mat4::Mat4(Float value) : Mat4(SQ_NULL)
	{
		classCtor(value);
	}

	Mat4::Mat4(Vec4 v0, Vec4 v1, Vec4 v2, Vec4 v3) : Mat4(SQ_NULL)
	{
		classCtor(v0, v1, v2, v3);
	}

	Mat4::Mat4(SQObject object) :
		Class("Mat4", object),
		METHOD_CTOR(makeIdentity),
		METHOD_CTOR(makeZero),
		METHOD_CTOR(makeOrthonormal),
		METHOD_CTOR(isUpper3x3Orthonormal),
		METHOD_CTOR(transpose),
		METHOD_CTOR(inverse),
		METHOD_CTOR(inverseLinTrafo),
		METHOD_CTOR(rotate),
		METHOD_CTOR(getRightVector),
		METHOD_CTOR(setRightVector),
		METHOD_CTOR(getAtVector),
		METHOD_CTOR(setAtVector),
		METHOD_CTOR(getUpVector),
		METHOD_CTOR(setUpVector),
		METHOD_CTOR(resetRotation),
		METHOD_CTOR(extractRotation),
		METHOD_CTOR(extractScaling),
		METHOD_CTOR(postRotateX),
		METHOD_CTOR(postRotateY),
		METHOD_CTOR(postRotateZ),
		METHOD_CTOR(preScale),
		METHOD_CTOR(postScale),
		METHOD_CTOR(swap)
	{
	}
}
