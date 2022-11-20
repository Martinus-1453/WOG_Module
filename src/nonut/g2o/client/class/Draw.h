#pragma once
#ifndef DRAW_H
#define DRAW_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Draw : public Class
	{
	public:
		Draw(int x, int y, std::string text);

		// Methods
		Function<void> top;
		Function<void,int, int, int> setColor;
		Function<Color> getColor;
		Function<void, float, float> setScale;
		Function<Size2d> getScale;
		Function<void, int, int> setPosition;
		Function<Position2d> getPosition;
		Function<void, int, int> setPositionPx;
		Function<Position2d> getPositionPx;
		Function<void, int, int> setPivotPoint;
		Function<void, int, int> setPivotPointPx;
		Function<Position2d> getPivotPoint;
		Function<Position2d> getPivotPointPx;

		// Properties
		Property<bool> visible;
		Property<std::string> text;
		Property<std::string> font;
		Property<int> alpha;
		Property<float> rotation;

		// Read-only properties
		Property<int, true> width;
		Property<int, true> widthPx;
		Property<int, true> height;
		Property<int, true> heightPx;
	};
}
#endif
