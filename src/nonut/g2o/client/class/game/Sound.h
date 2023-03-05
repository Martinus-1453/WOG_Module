#ifndef NONUT_G2O_CLIENT_CLASS_SOUND_H
#define NONUT_G2O_CLIENT_CLASS_SOUND_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sound : public Class
	{
	public:
		Sound(String fileName);

		// Methods
		Function<void> play;
		Function<void> stop;
		Function<Bool> isPlaying;

		// Properties
		Property<String> file;
		Property<Float> volume;
		Property<Bool> looping;
		Property<Float> balance;

		// Read-only properties
		Property<Float, true> playingTime;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_SOUND_H