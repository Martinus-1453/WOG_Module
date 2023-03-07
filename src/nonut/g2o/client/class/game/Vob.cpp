#include "Vob.h"

namespace nonut::g2o
{
	Vob::Vob(const String& model) : Vob(SQ_NULL)
	{
		classCtor(model);
	}

	Vob::Vob(const SQUserPointer ptr) : Vob(SQ_NULL)
	{
		classCtor(ptr);
	}

	Vob::Vob(const SQObject object, const String& className) :
		Class(className, object),
		METHOD_CTOR(beginMovement),
		METHOD_CTOR(endMovement),
		METHOD_CTOR(setHeadingAtWorld),
		METHOD_CTOR(getTrafoModelNodeToWorld),
		METHOD_CTOR(setPosition),
		METHOD_CTOR(getPosition),
		METHOD_CTOR(setRotation),
		METHOD_CTOR(getRotation),
		METHOD_CTOR(addToWorld),
		METHOD_CTOR(removeFromWorld),
		METHOD_CTOR(floor),
		PROPERTY_CTOR(objectName),
		PROPERTY_CTOR(matrix),
		PROPERTY_CTOR(cdDynamic),
		PROPERTY_CTOR(cdStatic),
		PROPERTY_CTOR(farClipZScale),
		PROPERTY_CTOR(visual),
		PROPERTY_CTOR(visualAlpha),
		PROPERTY_CTOR(sleeping),
		PROPERTY_CTOR(physicsEnabled),
		PROPERTY_CTOR(drawBBox3d),
		PROPERTY_CTOR(castDynShadow),
		PROPERTY_CTOR(bbox3dWorld),
		PROPERTY_CTOR(bbox3dLocal),
		PROPERTY_CTOR(isProjectile),
		PROPERTY_CTOR(isWater),
		PROPERTY_CTOR(velocity),
		PROPERTY_CTOR(isInMovement),
		PROPERTY_CTOR(ptr)
	{
	}
}
