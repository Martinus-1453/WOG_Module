#pragma once
#ifndef LINE3D_H
#define LINE3D_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Line3d : public Class
	{
		Line3d(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);

		// Methods
		Function<void> top;
		Function<void, Float, Float, Float> setBegin;
		Function<void, Float, Float, Float> setEnd;
		Function<void, Int, Int, Int> setColor;
		Function<Position3d> getBegin;
		Function<Position3d> getEnd;
		Function<Color> getColor;

		// Properties
		Property<Bool> visible;

	};
}
#endif
