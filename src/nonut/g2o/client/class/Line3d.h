#pragma once
#ifndef LINE3D_H
#define LINE3D_H

#include "nonut/core/Class.h"
#include "nonut/g2o/Shared/CustomTypes.h"

namespace nonut::g2o
{
	class Line3d : public Class
	{
		Line3d(float x1, float y1, float z1, float x2, float y2, float z2);

		// Methods
		Function<void> top;
		Function<void, float, float, float> setBegin;
		Function<void, float, float, float> setEnd;
		Function<void, int, int, int> setColor;
		Function<Position3d> getBegin;
		Function<Position3d> getEnd;
		Function<Color> getColor;

		// Properties
		Property<bool> visible;

	};
}
#endif
