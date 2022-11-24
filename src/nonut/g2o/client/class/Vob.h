#pragma once
#ifndef VOB_H
#define VOB_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Mob : public Class
	{
	protected:
		// Inheritance Ctor
		Vob(constexpr const char* className);
	public:
		Vob(String model);
		Vob(SQUserPointer ptr);

		// Methods
		Function<void> beginMovement;
		Function<void> endMovement;
		Function<void, Vec3> setHeadingAtWorld;
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
		Property<BBox3d&> bbox3dWorld;
		Property<BBox3d&> bbox3dLocal;
		
		

		// Read-only properties
		Property<Bool, true> isProjectile;
		Property<Bool, true> isWater;
		Property<Vec3, true> velocity;
		Property<Bool, true> isInMovement;
		Property<SQUserPointer, true> ptr;
	};
}
#endif
