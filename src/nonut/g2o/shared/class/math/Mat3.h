#ifndef NONUT_G2O_SHARED_CLASS_MAT3_H
#define NONUT_G2O_SHARED_CLASS_MAT3_H
#include "Class.h"
#include "Vec3.h"

namespace nonut::g2o
{
	class Mat3 : public Class
	{
	public:
		Mat3();
		Mat3(Float value);
		Mat3(Vec3 v0, Vec3 v1, Vec3 v2);
		Mat3(SQObject object);
		COPY_CTOR(Mat3);

		Function<void> makeIdentity;
		Function<void> makeZero;
		Function<void> makeOrthonormal;
		Function<Bool> isUpper3x3Orthonormal;
		Function<Mat3> transpose;
		Function<Mat3> inverse;
		Function<Vec3> rotate;
		Function<Vec3> getRightVector;
		Function<void, Vec3> setRightVector;
		Function<Vec3> getUpVector;
		Function<void, Vec3> setUpVector;
		Function<Vec3> getAtVector;
		Function<void, Vec3> setAtVector;
		Function<void> resetRotation;
		Function<Mat3> extractRotation;
		Function<Vec3> extractScaling;
		Function<void, Float> postRotateX;
		Function<void, Float> postRotateY;
		Function<void, Float> postRotateZ;
		Function<void, Vec3> preScale;
		Function<void, Float> postScale;
		// static methods
		Function<void, Mat3, Mat3> swap;
	};
}
#endif
