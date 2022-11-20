#pragma once
#ifndef SOUND_H
#define SOUND_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sound : public Class
	{
	public:
		Sound(std::string fileName);

		// Methods
		Function<void> play;
		Function<void> stop;
		Function<bool> isPlaying;

		// Properties
		Property<std::string> file;
		Property<float> volume;
		Property<bool> looping;
		Property<float> balance;

		// Read-only properties
		Property<float, true> playingTime;
	};
}
#endif
