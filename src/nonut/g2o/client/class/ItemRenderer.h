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
		ItemRenderer(Int x, Int y, Int width, Int height, String instance);

		// Methods
		Function<void> top;
		Function<void, Int, Int> setPosition;
		Function<void, Int, Int> setPositionPx;
		Function<void, Int, Int> setSize;
		Function<void, Int, Int> setSizePx;
		Function<Position2d> getPosition;
		Function<Position2d> getPositionPx;
		Function<Size2d> getSize;
		Function<Size2d> getSizePx;

		// Properties
		Property<Bool> visible;
		Property<Int> rotX;
		Property<Int> rotY;
		Property<Int> rotZ;
		Property<Int> zbias;
		Property<Bool> lightingswell;
		Property<String> visual;
		Property<String> instance;
	};
}
#endif
