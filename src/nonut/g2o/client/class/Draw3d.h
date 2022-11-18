#pragma once
#ifndef DRAW3D_H
#define DRAW3D_H
#include "nonut/core/Class.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class Draw3d : public Class
	{
	public:
		Draw3d(float x, float y, float z);

		// Methods
		Function<void> top;
		Function<void, int, int> setLineFont;
		Function<int, int> getLineFont;
		Function<void, int, int, int> setColor;
		Function<Color> getColor;
		Function<void, int, int, int, int> setLineColor;
		Function<Color, int> getLineColor;
		Function<void, int, int> setLineAlpha;
		Function<int, int> getLineAlpha;
		Function<void, std::string> insertText;
		Function<void, int> removeText;
		Function<std::string, int> getText;
		Function<void, int, std::string> setLineText;
		Function<std::string, int> getLineText;
		Function<void, int, int> setPosition;
		Function<Position2d> getPosition;
		Function<void, int, int> setPositionPx;
		Function<Position2d> getPositionPx;
		Function<void, float, float, float> setWorldPosition;
		Function<Position3d> getWorldPosition;

		// Properties
		Property<bool> visible;
		Property<std::string> font;
		Property<int> alpha;
		Property<int> distance;

		// Read-only properties
		Property<int, true> width;
		Property<int, true> widthPx;
		Property<int, true> height;
		Property<int, true> heightPx;
	};
}
#endif