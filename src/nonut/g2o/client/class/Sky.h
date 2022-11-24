#pragma once
#ifndef SKY_H
#define SKY_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sky : public StaticClass
	{
	public:
		// TODO: ctor for statics
		Sky();

		// Methods
		Function<void, Int, Int> setRainStartTime;
		Function<TimeHM> getRainStartTime;
		Function<void, Int, Int> setRainStopTime;
		Function<TimeHM> getRainStopTime;
		Function<void, Int, Int, Int> setFogColor;
		Function<void, Int, Int, Int> setCloudsColor;
		Function<void, Int, Int> setPlanterSize;
		Function<void, Int, Int, Int, Int, Int> setPlanetColor;
		Function<void, Int, Int, Int> setLightingColor;

		// Properties
		Property<Int> weather;
		Property<Bool> raining;
		Property<Bool> renderLightning;
		Property<Float> windScale;
		Property<Float> weatherWeight;
		Property<Bool> dontRain;
		Property<Bool> darkSky;
	};
}
#endif
