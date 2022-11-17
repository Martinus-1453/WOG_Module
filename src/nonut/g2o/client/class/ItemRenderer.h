#pragma once
#ifndef ITEM_RENDERER_H
#define ITEM_RENDERER_H

#include "nonut/core/Class.h"
#include "nonut/g2o/Shared/CustomTypes.h"

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
		Function<Position2D> getPosition;
		Function<Position2D> getPositionPx;
		Function<Size2D> getSize;
		Function<Size2D> getSizePx;

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
#endif // !ITEM_RENDERER_H
