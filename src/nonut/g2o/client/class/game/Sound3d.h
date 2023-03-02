#ifndef NONUT_G2O_CLIENT_CLASS_SOUND3D_H
#define NONUT_G2O_CLIENT_CLASS_SOUND3D_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
	class Sound3d : public Class
	{
	public:
		Sound3d(String fileName);

		// Methods
		Function<void> play;
		Function<void> stop;
		Function<Bool> isPlaying;
		//Function<void, Vob> setTargetVob;
		Function<void, Int> setTargetPlayer;

		// Properties
		Property<String> file;
		Property<Float> volume;
		Property<Bool> looping;
		Property<Float> obstruction;
		Property<Float> radius;
		Property<Float> coneAngle;
		Property<Float> reverbLevel;
		Property<Bool> ambient;
		Property<Float> pitchOffset;

		// Read-only properties
		Property<Float, true> playingTime;
	};
}
#endif // NONUT_G2O_CLIENT_CLASS_SOUND3D_H
