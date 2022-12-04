#include "Sprint.h"

#include <algorithm>

#include "event/ClientEventHandlers.h"
#include "constant/ClientConstants.h"

using ClientEventHandlers = nonut::g2o::ClientEventHandlers;
using ClientConstant = nonut::g2o::ClientConstants;

namespace wog
{
	Sprint::Sprint()
	{
		ClientEventHandlers::onKeyHandler.emplace_back([this](Int key)
			{
				if (key == ClientConstant::KEY_LSHIFT)
				{
					isActive = true;
					keyTimer = 0.f;
				}
			});

		ClientEventHandlers::onRenderHandler.emplace_back([this](float deltaTime)
			{
				update(deltaTime);
			});
	}

	void Sprint::update(float deltaTime)
	{
		if (exhaustionTimer > 0.f)
			exhaustionTimer = std::clamp(exhaustionTimer - deltaTime,
			0.f,
			EXHAUSTION_TIME);

		if(isActive)
		{
			keyTimer += deltaTime;

			if (keyTimer > KEY_TIMEOUT)
			{
				isActive = false;
				return;
			}

			if (exhaustionTimer <= 0.f)
			{
				stamina -= staminaDrain * deltaTime;

				if (stamina >= 0.f)
				{
					// Place here sprint thingy
				}
				else
				{
					exhaustionTimer = EXHAUSTION_TIME;
					stamina = 0.f;
					isActive = false;
				}
			}
		}
		else
		{
			if (!isExhausted())
			{
				stamina = std::clamp(
					stamina + staminaRegen * deltaTime,
					0.f,
					staminaMax);
			}
		}
	}

	Sprint* Sprint::get()
	{
		if (instance == nullptr)
		{
			instance = new Sprint();
		}
		return instance;
	}

	float Sprint::getStamina() const
	{
		return stamina;
	}

	float Sprint::getStaminaMax() const
	{
		return staminaMax;
	}

	bool Sprint::isExhausted() const
	{
		return exhaustionTimer > 0.f;
	}
}
