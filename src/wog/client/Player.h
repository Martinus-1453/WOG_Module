#ifndef WOG_CLIENT_PLAYER_H
#define WOG_CLIENT_PLAYER_H

#include "pch.h"

namespace wog
{
	class Player
	{
	public:
		static Player* get();

	protected:
		Player();

		static inline Player* instance = nullptr;
	};
}
#endif // WOG_CLIENT_PLAYER_H