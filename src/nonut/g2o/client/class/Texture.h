#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Texture : public Class
	{
		Texture(Int x, Int y, Int width, Int height, String txt);

		// Methods
		Function<void> top;
		Function<void, Int, Int, Int> setColor;
		Function<Color> getColor;
		Function<void, Int, Int> setPosition;
		Function<void, Int, Int> setPositionPx;
		Function<Position2d> getPosition;
		Function<Position2d> getPositionPx;
		Function<void, Int, Int> setPivotPoint;
		Function<void, Int, Int> setPivotPointPx;
		Function<Position2d> getPivotPoint;
		Function<Position2d> getPivotPointPx;
		Function<void, Int, Int> setSize;
		Function<void, Int, Int> setSizePx;
		Function<Size2d> getSize;
		Function<Size2d> getSizePx;
		Function<void, Int, Int, Int, Int> setRect;
		Function<void, Int, Int, Int, Int> setRectPx;
		Function<Rect> getRect;
		Function<Rect> getRectPx;
		Function<void, Float, Float, Float, Float> setUV;
		Function<UV> getUV;

		// Properties
		Property<Bool> visible;
		Property<String> file;
		Property<Int> alpha;
		Property<Float> rotation;
	};
}
#endif
