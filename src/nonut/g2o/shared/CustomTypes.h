#ifndef NONUT_G2O_SHARED_CUSTOM_TYPES_H
#define NONUT_G2O_SHARED_CUSTOM_TYPES_H

#include <string>

#include "Utils.h"

namespace nonut::g2o
{
	struct GameTime : CustomType
	{
		void convert(SQObject object) override;
		Int day{};
		Int hour{};
		Int min{};

		auto toTuple()
		{
			return std::make_tuple(day, hour, min);
		}
	};

	struct Position2d : CustomType
	{
		void convert(SQObject object) override;
		Int x{};
		Int y{};
		auto toTuple()
		{
			return std::make_tuple(x, y);
		}
	};

	struct Position3d : CustomType
	{
		void convert(SQObject object) override;
		Float x{};
		Float y{};
		Float z{};
		auto toTuple()
		{
			return std::make_tuple(x, y, z);
		}
	};

	struct Size2d : CustomType
	{
		void convert(SQObject object) override;
		Int width{};
		Int height{};
		auto toTuple()
		{
			return std::make_tuple(width, height);
		}
	};

	struct Rect : CustomType
	{
		void convert(SQObject object) override;
		Int x;
		Int y;
		Int width;
		Int height;
		auto toTuple()
		{
			return std::make_tuple(x, y, width, height);
		}
	};

	struct UV : CustomType
	{
		void convert(SQObject object) override;
		Float x;
		Float y;
		Float width;
		Float height;
		auto toTuple()
		{
			return std::make_tuple(x, y, width, height);
		}
	};

	struct Resolution : CustomType
	{
		void convert(SQObject object) override;
		Int x{};
		Int y{};
		Int bpp{};
		auto toTuple()
		{
			return std::make_tuple(x, y, bpp);
		}
	};

	struct Item : CustomType
	{
		void convert(SQObject object) override;
		Int instance{};
		Int amount{};
		String name{};
		auto toTuple()
		{
			return std::make_tuple(instance, amount, name);
		}
	};

	struct Color : CustomType
	{
		void convert(SQObject object) override;
		Int r{};
		Int g{};
		Int b{};
		auto toTuple()
		{
			return std::make_tuple(r, g, b);
		}
	};

	struct BodyVisual : CustomType
	{
		void convert(SQObject object) override;
		String bodyModel{};
		Int bodyTxt{};
		String headModel{};
		Int headTxt{};
		auto toTuple()
		{
			return std::make_tuple(bodyModel, bodyTxt, headModel, headTxt);
		}
	};

	struct NetworkStats : CustomType
	{
		void convert(SQObject object) override;
		Int packetReceived{};
		Int packetlossTotal{};
		Int packetlossLastSecond{};
		Int messagesInResendBuffer{};
		Int messageInSendBuffer{};
		Int bytesInResendBuffer{};
		Int bytesInSendBuffer{};
		auto toTuple()
		{
			return std::make_tuple(
				packetReceived,
				packetlossTotal,
				packetlossLastSecond,
				messagesInResendBuffer,
				messageInSendBuffer,
				bytesInResendBuffer,
				bytesInSendBuffer);
		}
	};
}
#endif // NONUT_G2O_SHARED_CUSTOM_TYPES_H
