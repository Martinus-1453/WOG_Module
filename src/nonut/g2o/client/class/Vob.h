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
		Vob(std::string model);
		Vob(SQUserPointer ptr);

		// Methods
		Function<void> beginMovement;
		Function<void> endMovement;
		Function<void, Vec3> setHeadingAtWorld;
		Function<Mat4, std::string> getTrafoModelNodeToWorld;
		Function<void, float, float, float> setPosition;
		Function<Position3d> getPosition;
		Function<void, float, float, float> setRotation;
		Function<Position3d> getRotation;
		Function<void> addToWorld;
		Function<void> removeFromWorld;
		Function<void> floor;

		// Properties
		Property<std::string> objectName;
		Property<Mat4> matrix;
		Property<bool> cdDynamic;
		Property<bool> cdStatic;
		Property<float> farClipZScale;
		Property<std::string> visual;
		Property<float> visualAlpha;
		Property<bool> sleeping;
		Property<bool> physicsEnabled;
		Property<bool> drawBBox3d;
		Property<bool> castDynShadow;
		Property<BBox3d&> bbox3dWorld;
		Property<BBox3d&> bbox3dLocal;
		
		

		// Read-only properties
		Property<bool, true> isProjectile;
		Property<bool, true> isWater;
		Property<Vec3, true> velocity;
		Property<bool, true> isInMovement;
		Property<SQUserPointer, true> ptr;
	};
}
#endif
