#ifndef NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
#define NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
#include "Function.h"
#include "CustomTypes.h"

#define SERVER_FUNCTIONS nonut::g2o::ServerFunctions::getInstance()
#define S_F SERVER_FUNCTIONS

namespace nonut::g2o
{
	class ServerFunctions
	{
	protected:
		ServerFunctions();
		static inline ServerFunctions* instance = nullptr;
	public:
		ServerFunctions(ServerFunctions& other) = delete;
		void operator=(const ServerFunctions&) = delete;
		static ServerFunctions* getInstance();

		// G2O functions
		Function<void, Int, Int> setPlayerHealth;
		Function<void, Int, Int> setPlayerMaxHealth;
		Function<void, Int, Int> setPlayerMana;
		Function<void, Int, Int> setPlayerMaxMana;
	};
}
#endif // NONUT_G2O_SERVER_FUNCTION_SERVER_FUNCTIONS_H
