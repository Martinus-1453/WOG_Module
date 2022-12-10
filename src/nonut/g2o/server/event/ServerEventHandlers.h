#ifndef NONUT_G2O_SERVER_EVENT_SERVER_EVENT_HANDLERS_H
#define NONUT_G2O_SERVER_EVENT_SERVER_EVENT_HANDLERS_H

#include <functional>
#include <string>
#include <vector>
#include "class/Packet.h"

namespace nonut::g2o
{
#define HANDLER_INIT(type, name) std::vector<std::function<type>> name ## Handler{}

	
	// Network
	static void onPacket(Int playerId, SQObject object);

	static void onPlayerChangeWeaponMode(Int playerId, Int oldWeaponMode, Int newWeaponMode);

	static void onPlayerMessage(Int playerId, String message);

	class ServerEventHandlers
	{
	public:
		// !!!INITIALIZATION!!!
		static void init();

		static inline std::map<ClientPacketType ,std::function<void(Int ,Packet&)>> onPacketHandler{};
		static inline HANDLER_INIT(void(Int, Int, Int), onPlayerChangeWeaponMode);
		static inline HANDLER_INIT(void(Int, String), onPlayerMessage);
	};
}
#endif // NONUT_G2O_SERVER_EVENT_SERVER_EVENT_HANDLERS_H
