#pragma once
#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

#include <string>

#include "nonut/core/Utils.h"

namespace nonut::g2o
{
	struct GameTime : CustomType
	{
		void convert(HSQOBJECT object) override;
		int day{};
		int hour{};
		int min{};
	};

	struct Position2D : CustomType
	{
		void convert(HSQOBJECT object) override;
		int x{};
		int y{};
	};

	struct Position3D : CustomType
	{
		void convert(HSQOBJECT object) override;
		int x{};
		int y{};
		int z{};
	};

	struct Size2D : CustomType
	{
		void convert(HSQOBJECT object) override;
		int width{};
		int height{};
	};

	struct Resolution : CustomType
	{
		void convert(HSQOBJECT object) override;
		int x{};
		int y{};
		int bpp{};
	};

	struct Item : CustomType
	{
		void convert(HSQOBJECT object) override;
		int instance{};
		int amount{};
		std::string name{};
	};

	struct Color : CustomType
	{
		void convert(HSQOBJECT object) override;
		int r{};
		int g{};
		int b{};
	};

	struct BodyVisual : CustomType
	{
		void convert(HSQOBJECT object) override;
		std::string bodyModel{};
		int bodyTxt{};
		std::string headModel{};
		int headTxt{};
	};

	struct NetworkStats : CustomType
	{
		void convert(HSQOBJECT object) override;
		int packetReceived{};
		int packetlossTotal{};
		int packetlossLastSecond{};
		int messagesInResendBuffer{};
		int messageInSendBuffer{};
		int bytesInResendBuffer{};
		int bytesInSendBuffer{};
	};
}

#endif