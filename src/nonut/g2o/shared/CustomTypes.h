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
	};

	struct Position2d : CustomType
	{
		void convert(SQObject object) override;
		Int x{};
		Int y{};
	};

	struct Position3d : CustomType
	{
		void convert(SQObject object) override;
		Float x{};
		Float y{};
		Float z{};
	};

	struct Size2d : CustomType
	{
		void convert(SQObject object) override;
		Int width{};
		Int height{};
	};

	struct Rect : CustomType
	{
		void convert(SQObject object) override;
		Int x;
		Int y;
		Int width;
		Int height;
	};

	struct UV : CustomType
	{
		void convert(SQObject object) override;
		Float x;
		Float y;
		Float width;
		Float height;
	};

	struct Resolution : CustomType
	{
		void convert(SQObject object) override;
		Int x{};
		Int y{};
		Int bpp{};
	};

	struct Item : CustomType
	{
		void convert(SQObject object) override;
		Int instance{};
		Int amount{};
		String name{};
	};

	struct Color : CustomType
	{
		void convert(SQObject object) override;
		Int r{};
		Int g{};
		Int b{};
	};

	struct BodyVisual : CustomType
	{
		void convert(SQObject object) override;
		String bodyModel{};
		Int bodyTxt{};
		String headModel{};
		Int headTxt{};
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
	};
}

#endif // NONUT_G2O_SHARED_CUSTOM_TYPES_H
