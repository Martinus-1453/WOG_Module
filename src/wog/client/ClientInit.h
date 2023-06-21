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
		ClientEventHandlers::init();
		ClientConstants::init();
		SharedConstants::init();
		std::ignore = HUD::get();
		std::ignore = Sprint::get();
		std::ignore = Player::get();
		std::ignore = Chat::get();

		ClientEventHandlers::onPacketHandler.emplace(
			nonut::ServerPacketType::HelloClient,
			[](g2o::Packet& packet)
			{
				auto result = packet.readString();
				SHARED_FUNCTIONS->print(result);
			});

		ClientEventHandlers::onMouseClickHandler.emplace_back([](Int key)
		{
			g2o::Packet packet{nonut::ClientPacketType::HelloServer};
			packet.writeInt32(key);
			String tekst = "Hello Server!";
			packet.writeString(tekst);

			if (key == ClientConstants::MOUSE_LMB)
			{
				const auto posVec3 = std::make_from_tuple<Vec3>(Camera::get()->getPosition().toTuple());
				const auto distanceVec3 = Camera::get()->vobMatrix.get().getAtVector() * 5000.f;
				SH_F->print("posVec: " + posVec3.toString());
				SH_F->print("disVec: " + posVec3.toString());

				if (auto ray = World::get()->traceRayFirstHit(
					posVec3,
					distanceVec3,
					ClientConstants::TRACERAY_POLY_NORMAL); !ray.isNull())
				{
					const auto sphere = new g2o::MobInter("Sphere.3ds");
					sphere->cdDynamic = true;
					sphere->name = "sphere";
					sphere->focusOverride = true;
					const Vec3 rayIntersect = ray.intersect;
					SH_F->print("intersectVec: " + rayIntersect.toString());
					std::apply(sphere->setPosition, rayIntersect.toTuple());
					sphere->floor();
					sphere->addToWorld();
				}

				SHARED_FUNCTIONS->print("LMB");

				packet.writeInt32(
					CLIENT_FUNCTIONS->getPlayerHealth(ClientConstants::heroId) + 5);
			}
			else if (key == ClientConstants::MOUSE_MMB)
			{
				SHARED_FUNCTIONS->print("MMB");

				packet.writeInt32(
					CLIENT_FUNCTIONS->getPlayerHealth(ClientConstants::heroId) - 5);
			}
			else if (key == ClientConstants::MOUSE_RMB)
			{
				SHARED_FUNCTIONS->print("RMB");

				packet.writeInt32(
					CLIENT_FUNCTIONS->getPlayerMaxHealth(ClientConstants::heroId));
				auto pos = g2o::Camera::get()->getPosition();
				String coord = std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z);
				SH_F->print(coord);
				g2o::Camera::get()->setPosition(0, 0, 0);
				coord = std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z);
				SH_F->print(coord);
			}
			packet.send(SharedConstants::RELIABLE_ORDERED);
		});
	}
}
#endif // WOG_CLIENT_CLIENT_INIT_H
