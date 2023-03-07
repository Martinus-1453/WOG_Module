#ifndef NONUT_G2O_CLIENT_CLASS_LINE_H
#define NONUT_G2O_CLIENT_CLASS_LINE_H

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Line : public Class
	{
		Line(Int x1, Int y1, Int x2, Int y2);

		// Methods
		Function<void> top;
		Function<void, Int, Int> setBegin;
		Function<void, Int, Int> setEnd;
		Function<void, Int, Int, Int> setColor;
		Function<Position2d> getBegin;
		Function<Position2d> getEnd;
		Function<Color> getColor;

		// Properties
		Property<Bool> visible;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_LINE_H
