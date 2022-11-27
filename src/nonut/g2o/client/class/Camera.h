#ifndef NONUT_G2O_CLIENT_CLASS_CAMERA_H
#define NONUT_G2O_CLIENT_CLASS_CAMERA_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Camera : public StaticClass
	{
	public:
		// TODO: Find a way to initialize static class Camera :)
		Camera();
		
		// Methods
		Function<Position3d> getPosition;
		Function<void, Float, Float, Float> setPosition;
		Function<Position3d> getRotation;
		Function<void, Float, Float, Float> setRotation;
		Function<Position2d, Float, Float, Float> project;
		// TODO: Handle classes as function parameter o.o
		Function<void, Vob> setTargetVob;
		Function<void, Int> setTargetPlayer;

		// Properties
		Property<Mat4> vobMatrix;
		Property<Mat4> viewMatrix;
		Property<Mat4> projectionMatrix;
		Property<Mat4> worldMatrix;
		Property<Mat4> worldViewMatrix;
		Property<Bool> modeChangeEnabled;
		Property<String> mode;
		Property<Bool> movementEnabled;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_CAMERA_H
