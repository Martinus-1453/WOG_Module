#pragma once
#ifndef CAMERA_H
#define CAMERA_H
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
		Function<void, float, float, float> setPosition;
		Function<Position3d> getRotation;
		Function<void, float, float, float> setRotation;
		Function<Position2d, float, float, float> project;
		// TODO: Handle classes as function parameter o.o
		Function<void, Vob> setTargetVob;
		Function<void, int> setTargetPlayer;

		// Properties
		Property<Mat4> vobMatrix;
		Property<Mat4> viewMatrix;
		Property<Mat4> projectionMatrix;
		Property<Mat4> worldMatrix;
		Property<Mat4> worldViewMatrix;
		Property<bool> modeChangeEnabled;
		Property<std::string> mode;
		Property<bool> movementEnabled;
	};
}
#endif
