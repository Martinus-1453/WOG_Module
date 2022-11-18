#include "CustomTypes.h"

#include "nonut/core/Array.h"
#include "nonut/core/Property.h"

namespace nonut::g2o
{
#define GET_SLOT(slot, type) slot = arrayWrapper.get<type>(#slot)
	void GameTime::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(day, int);
		GET_SLOT(hour, int);
		GET_SLOT(min, int);
	}

	void Position2d::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(x, int);
		GET_SLOT(y, int);
	}

	void Position3d::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(x, float);
		GET_SLOT(y, float);
		GET_SLOT(z, float);
	}

	void Size2d::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(width, int);
		GET_SLOT(height, int);
	}

	void Rect::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(x, int);
		GET_SLOT(y, int);
		GET_SLOT(width, int);
		GET_SLOT(height, int);
	}

	void UV::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(x, float);
		GET_SLOT(y, float);
		GET_SLOT(width, float);
		GET_SLOT(height, float);
	}

	void Resolution::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(x, int);
		GET_SLOT(y, int);
		GET_SLOT(bpp, int);
	}

	void Item::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(instance, int);
		GET_SLOT(amount, int);
		GET_SLOT(name, std::string);
	}

	void Color::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(r, int);
		GET_SLOT(g, int);
		GET_SLOT(b, int);
	}

	void BodyVisual::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(bodyModel, std::string);
		GET_SLOT(bodyTxt, int);
		GET_SLOT(headModel, std::string);
		GET_SLOT(headTxt, int);
	}

	void NetworkStats::convert(HSQOBJECT object)
	{
		Array arrayWrapper(object);
		GET_SLOT(packetReceived, int);
		GET_SLOT(packetlossTotal, int);
		GET_SLOT(packetlossLastSecond, int);
		GET_SLOT(messagesInResendBuffer, int);
		GET_SLOT(messageInSendBuffer, int);
		GET_SLOT(bytesInResendBuffer, int);
		GET_SLOT(bytesInSendBuffer, int);
	}
}
