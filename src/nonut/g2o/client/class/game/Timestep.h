#ifndef NONUT_G2O_CLIENT_CLASS_TIMESTEP_H
#define NONUT_G2O_CLIENT_CLASS_TIMESTEP_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Timestep : public Class
	{
	public:
		// TODO: CHECK IF THIS WORKS THIS WAY!
		Timestep();

		// Methods
		Function<void> reset;
		Function<void, Float> update;

		// Properties
		Property<Float> factorMotion;

		// Read-only properties
		Property<Float, true> frameTime;
		Property<Float, true> totalTime;
		Property<Float, true> frameTimeSecs;
		Property<Float, true> totalTimeSecs;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_TIMESTEP_H
