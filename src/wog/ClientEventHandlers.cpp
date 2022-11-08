#include "pch.h"
#include "ClientEventHandlers.h"

#include "nonut/Function.h"

namespace wog
{
	void onKey(int key)
	{
		nonut::Function<void, std::string> print("print");
		print(std::string(std::to_string(key)));
	}
}
