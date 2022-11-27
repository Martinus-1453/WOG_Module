#ifndef NONUT_G2O_CLIENT_CLASS_DRAW_H
#define NONUT_G2O_CLIENT_CLASS_DRAW_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Draw : public Class
	{
	public:
		Draw(Int x, Int y, String text);

		// Methods
		Function<void> top;
		Function<void,Int, Int, Int> setColor;
		Function<Color> getColor;
		Function<void, Float, Float> setScale;
		Function<Size2d> getScale;
		Function<void, Int, Int> setPosition;
		Function<Position2d> getPosition;
		Function<void, Int, Int> setPositionPx;
		Function<Position2d> getPositionPx;
		Function<void, Int, Int> setPivotPoint;
		Function<void, Int, Int> setPivotPointPx;
		Function<Position2d> getPivotPoint;
		Function<Position2d> getPivotPointPx;

		// Properties
		Property<Bool> visible;
		Property<String> text;
		Property<String> font;
		Property<Int> alpha;
		Property<Float> rotation;

		// Read-only properties
		Property<Int, true> width;
		Property<Int, true> widthPx;
		Property<Int, true> height;
		Property<Int, true> heightPx;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_DRAW_H
