#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Texture : public Class
	{
		Texture(int x, int y, int width, int height, std::string txt);

		// Methods
		Function<void> top;
		Function<void, int, int, int> setColor;
		Function<Color> getColor;
		Function<void, int, int> setPosition;
		Function<void, int, int> setPositionPx;
		Function<Position2d> getPosition;
		Function<Position2d> getPositionPx;
		Function<void, int, int> setPivotPoint;
		Function<void, int, int> setPivotPointPx;
		Function<Position2d> getPivotPoint;
		Function<Position2d> getPivotPointPx;
		Function<void, int, int> setSize;
		Function<void, int, int> setSizePx;
		Function<Size2d> getSize;
		Function<Size2d> getSizePx;
		Function<void, int, int, int, int> setRect;
		Function<void, int, int, int, int> setRectPx;
		Function<Rect> getRect;
		Function<Rect> getRectPx;
		Function<void, float, float, float, float> setUV;
		Function<UV> getUV;

		// Properties
		Property<bool> visible;
		Property<std::string> file;
		Property<int> alpha;
		Property<float> rotation;
	};
}
#endif
