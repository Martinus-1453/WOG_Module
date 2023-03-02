#include "Mat3.h"

namespace nonut::g2o
{
	Mat3::Mat3() : Mat3(SQ_NULL)
	{
		classCtor();
	}

	Mat3::Mat3(Float value) : Mat3(SQ_NULL)
	{
		classCtor(value);
	}

	Mat3::Mat3(Vec3 v0, Vec3 v1, Vec3 v2) : Mat3(SQ_NULL)
	{
		classCtor(v0, v1, v2);
	}

	Mat3::Mat3(SQObject object) :
		Class("Mat3", object),
		METHOD_CTOR(makeIdentity),
		METHOD_CTOR(makeZero),
		METHOD_CTOR(makeOrthonormal),
		METHOD_CTOR(isUpper3x3Orthonormal),
		METHOD_CTOR(transpose),
		METHOD_CTOR(inverse),
		METHOD_CTOR(rotate),
		METHOD_CTOR(getRightVector),
		METHOD_CTOR(setRightVector),
		METHOD_CTOR(getUpVector),
		METHOD_CTOR(setUpVector),
		METHOD_CTOR(getAtVector),
		METHOD_CTOR(setAtVector),
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
