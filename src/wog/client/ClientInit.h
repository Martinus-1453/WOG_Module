#ifndef WOG_CLIENT_CLIENT_INIT_H
#define WOG_CLIENT_CLIENT_INIT_H
#include "Chat.h"
#include "HUD.h"
#include "CommonHeader.h"
#include "Player.h"
#include "Sprint.h"

#include "constant/ClientConstants.h"
#include "constant/SharedConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/SharedFunctions.h"
#include "StringHelpers.h"
#include "class/game/Camera.h"
#include "class/game/Mob.h"
#include "class/game/MobInter.h"
#include "class/game/World.h"
#include "PacketHelper.h"
#include "InputHandler.h"
#include "NoNutInitClient.h"

using namespace SqModule;

using ClientConstants = g2o::ClientConstants;
using ClientEventHandlers = g2o::ClientEventHandlers;
using SharedConstants = g2o::SharedConstants;
using Camera = g2o::Camera;
using Vec3 = g2o::Vec3;
using Mat4 = g2o::Mat4;
using Vob = g2o::Vob;
using World = g2o::World;

namespace wog
{
	inline void clientInit()
	{
		g2o::NoNutInitClient();
		std::ignore = HUD::get();
		std::ignore = Sprint::get();
		std::ignore = Player::get();
		std::ignore = Chat::get();
	}
}
#endif // WOG_CLIENT_CLIENT_INIT_H
