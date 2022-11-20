#pragma once
#ifndef SOUND3D_H
#define SOUND3D_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sound3d : public Class
	{
	public:
		Sound3d(std::string fileName);

		// Methods
		Function<void> play;
		Function<void> stop;
		Function<bool> isPlaying;
		//Function<void, Vob> setTargetVob;
		Function<void, int> setTargetPlayer;

		// Properties
		Property<std::string> file;
		Property<float> volume;
		Property<bool> looping;
		Property<float> obstruction;
		Property<float> radius;
		Property<float> coneAngle;
		Property<float> reverbLevel;
		Property<bool> ambient;
		Property<float> pitchOffset;

		// Read-only properties
		Property<float, true> playingTime;
	};
}
#endif
