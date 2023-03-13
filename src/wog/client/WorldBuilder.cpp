#include "WorldBuilder.h"

#include "constant/ClientConstants.h"
#include "event/ClientEventHandlers.h"
#include "function/ClientFunctions.h"
#include "class/game/Camera.h"

using ClientEventHandlers = g2o::ClientEventHandlers;
using ClientConstant = g2o::ClientConstants;
using Camera = g2o::Camera;
using Vec3 = g2o::Vec3;
using Mat4 = g2o::Mat4;
using Resolution = g2o::Resolution;
using Position3d = g2o::Position3d;

namespace wog
{
	WorldBuilder::WorldBuilder()
	{
		ClientEventHandlers::onRenderHandler.emplace_back([this](float deltaTime)
		{
			move(deltaTime);
		});

		ClientEventHandlers::onMouseMoveHandler.emplace_back([this](int x, int y)
		{
			rotate(x, y);
		});
	}

	void WorldBuilder::move(float deltaTime)
	{
		if (!isEnabled)
		{
			return;
		}

		Vec3 position = std::make_from_tuple<Vec3>(Camera::get()->getPosition().toTuple());

		Mat4 matrix = Camera::get()->vobMatrix.get();
		Vec3 vecForward = matrix.getAtVector();
		Vec3 vecRight = matrix.getRightVector();

		if (C_F->isKeyPressed(ClientConstant::KEY_W))
		{
			position += vecForward * MOVEMENT_SPEED;
		}

		if (C_F->isKeyPressed(ClientConstant::KEY_S))
		{
			position -= vecForward * MOVEMENT_SPEED;
		}

		if (C_F->isKeyPressed(ClientConstant::KEY_A))
		{
			position -= vecRight * MOVEMENT_SPEED;
		}

		if (C_F->isKeyPressed(ClientConstant::KEY_D))
		{
			position += vecRight * MOVEMENT_SPEED;
		}

		std::apply(Camera::get()->setPosition, position.toTuple());
	}

	void WorldBuilder::rotate(int x, int y)
	{
		if (isEnabled)
		{
			Position3d rotation = Camera::get()->getRotation();
			const Resolution resolution = C_F->getResolution();

			rotation.x += static_cast<float>(x) / static_cast<float>(resolution.x) * ROTATION_SPEED;
			rotation.y += static_cast<float>(y) / static_cast<float>(resolution.y) * ROTATION_SPEED;

			Camera::get()->setRotation(rotation.x, rotation.y, rotation.z);
		}
	}

	WorldBuilder* WorldBuilder::get()
	{
		if (instance == nullptr)
		{
			instance = new WorldBuilder();
		}
		return instance;
	}

	void WorldBuilder::enable(bool enabled)
	{
		if (isEnabled != enabled)
		{
			Camera::get()->modeChangeEnabled = !enabled;
			Camera::get()->movementEnabled = !enabled;

			C_F->setFreeze(enabled);

			isEnabled = enabled;
		}
	}
}