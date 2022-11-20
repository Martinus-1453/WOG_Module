#pragma once
#ifndef LINE_H
#define LINE_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Line : public Class
	{
		Line(int x1, int y1, int x2, int y2);

		// Methods
		Function<void> top;
		Function<void, int, int> setBegin;
		Function<void, int, int> setEnd;
		Function<void, int, int, int> setColor;
		Function<Position2d> getBegin;
		Function<Position2d> getEnd;
		Function<Color> getColor;

		// Properties
		Property<bool> visible;
		
	};
}
#endif
