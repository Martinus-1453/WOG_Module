#ifndef NONUT_G2O_SHARED_FUNCTION_SHARED_FUNCTIONS_H
#define NONUT_G2O_SHARED_FUNCTION_SHARED_FUNCTIONS_H
#include "Function.h"
#include "CustomTypes.h"

#define SHARED_FUNCTIONS nonut::g2o::SharedFunctions::getInstance()
#define SH_F SHARED_FUNCTIONS

namespace nonut::g2o
{
	class SharedFunctions
	{
	protected:
		SharedFunctions();
		static SharedFunctions* instance;
	public:
		SharedFunctions(SharedFunctions& other) = delete;
		void operator=(const SharedFunctions&) = delete;
		static SharedFunctions* getInstance();

		// G2O functions
		Function<void, String> print;
	};
}
#endif // NONUT_G2O_SHARED_FUNCTION_SHARED_FUNCTIONS_H
