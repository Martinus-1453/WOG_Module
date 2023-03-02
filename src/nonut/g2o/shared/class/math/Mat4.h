#ifndef NONUT_G2O_SHARED_CLASS_MAT4_H
#define NONUT_G2O_SHARED_CLASS_MAT4_H
#include "Class.h"
#include "Mat3.h"
#include "Vec3.h"
#include "Vec4.h"

namespace nonut::g2o
{
	class Mat4 : public Class
	{
	public:
		Mat4();
		Mat4(Float value);
		Mat4(Vec4 v0, Vec4 v1, Vec4 v2, Vec4 v3);
		Mat4(SQObject object);
		COPY_CTOR(Mat4);

		Function<void> makeIdentity;
		Function<void> makeZero;
		Function<void> makeOrthonormal;
		Function<Bool> isUpper3x3Orthonormal;
		Function<Mat4> transpose;
		Function<Mat4> inverse;
		Function<Mat4> inverseLinTrafo;
		Function<Vec3, Vec3> rotate;
		Function<Vec3> getRightVector;
		Function<void, Vec3> setRightVector;
		Function<Vec3> getAtVector;
		Function<void, Vec3> setAtVector;
		Function<Vec3> getUpVector;
		Function<void, Vec3> setUpVector;
		Function<void> resetRotation;
		Function<Mat3> extractRotation;
		Function<Vec3> extractScaling;
		Function<void, Float> postRotateX;
		Function<void, Float> postRotateY;
		Function<void, Float> postRotateZ;
		Function<void, Vec3> preScale;
		Function<void, Vec3> postScale;
		Function<void, Mat4, Mat4> swap;
	};
}
#endif //NONUT_G2O_SHARED_CLASS_MAT4_H
