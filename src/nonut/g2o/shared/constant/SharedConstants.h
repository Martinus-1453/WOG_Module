#ifndef NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS_H
#define NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS_H
#include "pch.h"

namespace nonut::g2o
{
	class SharedConstants
	{
	public:
		static void init();

		static inline Int UNRELIABLE = 0;
		static inline Int UNRELIABLE_SEQUENCED = 0;
		static inline Int RELIABLE = 0;
		static inline Int RELIABLE_ORDERED = 0;
		static inline Int RELIABLE_SEQUENCED = 0;
	};
}
#endif // NONUT_G2O_SHARED_CONSTANT_SHARED_CONSTANTS_H
