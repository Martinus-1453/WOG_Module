#ifndef WOG_CLIENT_PLAYER_H
#define WOG_CLIENT_PLAYER_H
#include "WogHeader.h"

namespace wog
{
	class Player : public Singleton<Player>
	{
	public:

	protected:
		Player();

		friend Singleton;
	};
}
#endif // WOG_CLIENT_PLAYER_H
