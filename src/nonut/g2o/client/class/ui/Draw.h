#ifndef NONUT_G2O_CLIENT_CLASS_DRAW_H
#define NONUT_G2O_CLIENT_CLASS_DRAW_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

	namespace nonut::g2o
{

	/// @brief This class represents text visible on the screen.
	class Draw : public Class
	{
	public:
		/// @param x the x position in virtuals.
		/// @param y the y position in virtuals.
		/// @param text the text to be shown.
		Draw(Int x, Int y, String text);

		// Methods
		/// @brief This method will move the draw text at the end of the render queue. It will be visible at the top of the screen (other elements will be covered by it).
		Function<void> top;
		/// @brief This method will set the text color.
		/// @param r: the red color component in RGB model.
		/// @param g: the green color component in RGB model.
		/// @param b: the blue color component in RGB model.
		Function<void, Int, Int, Int> setColor;
		/// @brief This method will get the text color.
		/// @return {r, g, b} : the draw color.
		Function<Color> getColor;
		/// @brief This method will set the scale of the text.
		/// @param width: the scale factor on x axis.
		/// @param height: the scale factor on y axis.
		Function<void, Float, Float> setScale;
		/// @brief This method will get the scale of the text.
		/// @return {width, height}: the draw scale.
		Function<Size2d> getScale;
		/// @brief This method will set the text position on screen in virtuals.
		/// @param x: the x position in virtuals.
		/// @param y: the y position in virtuals.
		Function<void, Int, Int> setPosition;
		/// @brief This method will get the text position on screen in virtuals.
		/// @return {x, y}: the draw position on screen.
		Function<Position2d> getPosition;
		/// @brief This method will set the text position on screen in pixels.
		/// @param x: the x position in pixels.
		/// @param y: the y position in pixels.
		Function<void, Int, Int> setPositionPx;
		/// @brief This method will get the text position on screen in pixels.
		/// @return {x, y}: the draw position on screen.
		Function<Position2d> getPositionPx;
		/// @brief This method will set the pivot point of the text in virtuals (Offset from the center of the draw). All rotations will be done relative to this point.
		/// @param x: the x offset in virtuals.
		/// @param y: the y offset in virtuals.
		Function<void, Int, Int> setPivotPoint;
		/// @brief This method will set the pivot point of the text in pixels (Offset from the center of the draw). All rotations will be done relative to this point.
		/// @param x: the x offset in pixels.
		/// @param y: the y offset in pixels.
		Function<void, Int, Int> setPivotPointPx;
		/// @brief This method will get the pivot point of the text in virtuals (Offset from the center of the draw).
		/// @return {x, y}: the offset in virtuals. The default pivot point value is {x=0,y=0}
		Function<Position2d> getPivotPoint;
		/// @brief This method will get the pivot point of the text in pixels (Offset from the center of the draw).
		/// @return {x, y}: the offset in pixels. The default pivot point value is {x=0,y=0}
		Function<Position2d> getPivotPointPx;

		// Properties
		/// @brief Represents the visibility state of the text.
		Property<Bool> visible;
		/// @brief Represents the text displayed by the draw.
		Property<String> text;
		/// @brief Represents the font name used by the text.
		Property<String> font;
		/// @brief Represents the text alpha color component in RGBA model.
		Property<Int> alpha;
		/// @brief Represents the rotation of the text in degrees. The rotation is performed clockwise around the draw pivot point.
		/// @see To change that center of rotation, see @setPivotPoint and @setPivotPointPx.
		Property<Float> rotation;

		// Read-only properties
		/// @brief Represents the width of the text in virtuals.
		Property<Int, true> width;
		/// @brief Represents the width of the text in pixels.
		Property<Int, true> widthPx;
		/// @brief Represents the height of the text in virtuals.
		Property<Int, true> height;
		/// @brief Represents the height of the text in pixels.
		Property<Int, true> heightPx;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_DRAW_H
