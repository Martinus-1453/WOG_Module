#ifndef NONUT_G2O_CLIENT_CLASS_VOB_H
#define NONUT_G2O_CLIENT_CLASS_VOB_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"
#include "class/math/BBox3d.h"
#include "class/math/Mat4.h"
#include "class/math/Vec3.h"

namespace nonut::g2o
{
	class Vob : public Class
	{
	public:
		Vob(const String& model);
		Vob(SQUserPointer ptr);
		Vob(SQObject object, const String& className = "Vob");
		COPY_CTOR(Vob);

		// Methods
		Function<void> beginMovement;
		Function<void> endMovement;
		Function<void, const Vec3&> setHeadingAtWorld;
		Function<Mat4, String> getTrafoModelNodeToWorld;
		Function<void, Float, Float, Float> setPosition;
		Function<Position3d> getPosition;
		Function<void, Float, Float, Float> setRotation;
		Function<Position3d> getRotation;
		Function<void> addToWorld;
		Function<void> removeFromWorld;
		Function<void> floor;

		// Properties
		Property<String> objectName;
		Property<Mat4> matrix;
		Property<Bool> cdDynamic;
		Property<Bool> cdStatic;
		Property<Float> farClipZScale;
		Property<String> visual;
		Property<Float> visualAlpha;
		Property<Bool> sleeping;
		Property<Bool> physicsEnabled;
		Property<Bool> drawBBox3d;
		Property<Bool> castDynShadow;
		Property<BBox3d> bbox3dWorld;
		Property<BBox3d> bbox3dLocal;

		// Read-only properties
		Property<Bool, true> isProjectile;
		Property<Bool, true> isWater;
		Property<Vec3, true> velocity;
		Property<Bool, true> isInMovement;
		Property<SQUserPointer, true> ptr;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_VOB_H
