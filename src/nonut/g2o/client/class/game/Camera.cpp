#include "Camera.h"

namespace nonut::g2o
{
	Camera* Camera::get()
	{
		if (instance == nullptr)
		{
			instance = new Camera();
		}
		return instance;
	}

	Camera::Camera():
		StaticClass("Camera"),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(getRotation),
		METHOD_CTOR(setRotation),
		METHOD_CTOR(project),
		METHOD_CTOR(setTargetVob),
		METHOD_CTOR(setTargetPlayer),
		PROPERTY_CTOR(vobMatrix),
		PROPERTY_CTOR(viewMatrix),
		PROPERTY_CTOR(projectionMatrix),
		PROPERTY_CTOR(worldMatrix),
		PROPERTY_CTOR(worldViewMatrix),
		PROPERTY_CTOR(modeChangeEnabled),
		PROPERTY_CTOR(mode),
		PROPERTY_CTOR(movementEnabled)
	{
	}
}
