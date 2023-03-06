#ifndef WOG_CLIENT_CLIENT_INIT_H
#define WOG_CLIENT_CLIENT_INIT_H
#include "Chat.h"
#include "HUD.h"
#include "pch.h"
#include "Player.h"
#include "Sprint.h"

#include "constant/ClientConstants.h"
#include "constant/SharedConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/SharedFunctions.h"
#include "StringHelpers.h"
#include "class/game/Camera.h"
#include "class/game/World.h"	

using namespace SqModule;

using ClientConstants = nonut::g2o::ClientConstants;
using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using SharedConstants = nonut::g2o::SharedConstants;

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
			[](nonut::g2o::Packet& packet)
			{
				auto result = packet.readString();
				SHARED_FUNCTIONS->print(result);
			});

		ClientEventHandlers::onMouseClickHandler.emplace_back([](Int key)
			{
				nonut::g2o::Packet packet{nonut::ClientPacketType::HelloServer};
				packet.writeInt32(key);
				String tekst = "Hello Server!";
				packet.writeString(tekst);

				if (key == ClientConstants::MOUSE_LMB)
				{
					g2o::Mat4 mat = g2o::Camera::get()->vobMatrix;
					g2o::Position3d pos = g2o::Camera::get()->getPosition();
					g2o::Vec3 posVec3(pos.x, pos.y, pos.z);
					auto atVec3 = mat.getAtVector();
					g2o::Vec3 distanceVec3 = posVec3 * 5000;
					SH_F->print("posVec: " + std::to_string(posVec3.x) + " " + std::to_string(posVec3.y) + " " + std::to_string(posVec3.z));
					SH_F->print("disVec: " + std::to_string(distanceVec3.x) + " " + std::to_string(distanceVec3.y) + " " + std::to_string(distanceVec3.z));
					auto ray = g2o::World::get()->traceRayFirstHit(posVec3, distanceVec3, ClientConstants::TRACERAY_POLY_NORMAL);
					if (!ray.isNull())
					{
						g2o::Vob* sphere = new g2o::Vob("Sphere.3ds");
						g2o::Vec3 rayIntersect = ray.intersect;
						if (ray.vob.get() != nullptr)
							SH_F->print("Znalazlem voba");
						SH_F->print("intersectVec: " + std::to_string(rayIntersect.x) + " " + std::to_string(rayIntersect.y) + " " + std::to_string(rayIntersect.z));
						sphere->setPosition(rayIntersect.x, rayIntersect.y, rayIntersect.z);
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
					auto pos = nonut::g2o::Camera::get()->getPosition();
					String coord = std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z);
					SH_F->print(coord);
					nonut::g2o::Camera::get()->setPosition(0, 0, 0);
					coord = std::to_string(pos.x) + " " + std::to_string(pos.y) + " " + std::to_string(pos.z);
					SH_F->print(coord);
				}
				packet.send(SharedConstants::RELIABLE_ORDERED);
			});
	}
}
#endif // WOG_CLIENT_CLIENT_INIT_H
