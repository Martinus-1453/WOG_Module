#pragma once
#ifndef ITEM_RENDERER_H
#define ITEM_RENDERER_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class ItemRenderer : public Class
	{
	public:
		ItemRenderer(int x, int y, int width, int height, std::string instance);

		// Methods
		Function<void> top;
		Function<void, int, int> setPosition;
		Function<void, int, int> setPositionPx;
		Function<void, int, int> setSize;
		Function<void, int, int> setSizePx;
		Function<Position2d> getPosition;
		Function<Position2d> getPositionPx;
		Function<Size2d> getSize;
		Function<Size2d> getSizePx;

		// Properties
		Property<bool> visible;
		Property<int> rotX;
		Property<int> rotY;
		Property<int> rotZ;
		Property<int> zbias;
		Property<bool> lightingswell;
		Property<std::string> visual;
		Property<std::string> instance;
	};
}
#endif
