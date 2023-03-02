#ifndef NONUT_G2O_CLIENT_CLASS_DRAW3D_H
#define NONUT_G2O_CLIENT_CLASS_DRAW3D_H
#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Draw3d : public Class
	{
	public:
		Draw3d(Float x, Float y, Float z);

		// Methods
		Function<void> top;
		Function<void, Int, Int> setLineFont;
		Function<Int, Int> getLineFont;
		Function<void, Int, Int, Int> setColor;
		Function<Color> getColor;
		Function<void, Int, Int, Int, Int> setLineColor;
		Function<Color, Int> getLineColor;
		Function<void, Int, Int> setLineAlpha;
		Function<Int, Int> getLineAlpha;
		Function<void, String> insertText;
		Function<void, Int> removeText;
		Function<String, Int> getText;
		Function<void, Int, String> setLineText;
		Function<String, Int> getLineText;
		Function<void, Int, Int> setPosition;
		Function<Position2d> getPosition;
		Function<void, Int, Int> setPositionPx;
		Function<Position2d> getPositionPx;
		Function<void, Float, Float, Float> setWorldPosition;
		Function<Position3d> getWorldPosition;

		// Properties
		Property<Bool> visible;
		Property<String> font;
		Property<Int> alpha;
		Property<Int> distance;

		// Read-only properties
		Property<Int, true> width;
		Property<Int, true> widthPx;
		Property<Int, true> height;
		Property<Int, true> heightPx;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_DRAW3D_H
