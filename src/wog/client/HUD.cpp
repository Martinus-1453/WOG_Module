#include "HUD.h"

#include <algorithm>

#include "constant/ClientConstants.h"
#include "function/ClientFunctions.h"
#include "Virt.h"
#include "event/ClientEventHandlers.h"
#include "Sprint.h"

using ClientConstants = nonut::g2o::ClientConstants;
using Virt = nonut::g2o::Virt;
using TextureSize = std::pair<float, float>;

constexpr auto scale = 0.65f;
constexpr TextureSize TEXTURE_BAR{ 316.f * scale, 128.f * scale };
constexpr TextureSize TEXTURE_SPRINT{ 502.f * scale, 33.f * scale };

constexpr auto uvBias = 0.004f;

namespace wog
{
	HUD* HUD::get()
	{
		if (instance == nullptr)
		{
			instance = new HUD();
		}
		return instance;
	}

	/*void processVerticalBar(nonut::g2o::Texture& bar, float percentage, Int x, Int y)
	{
		const auto height = texture2Height * percentage;
		bar.setUV(0.f, 1.f - percentage, 1.0f, percentage);
		bar.setSize(C_F->anx(texture2Width), C_F->any(height));
		bar.setPosition(
			x,
			y - C_F->any(height) - C_F->any(texture12diff));
	}*/

	void processHorizontalBar(nonut::g2o::Texture& bar, float percentage, TextureSize textureSize)
	{
		const auto width = std::floorf(textureSize.first * percentage);

		bar.setUV(0.f, 0.f, percentage, 1.f);
		bar.setSize(C_F->anx(width), C_F->any(textureSize.second));
	}

	void processHorizontalBarMirrored(nonut::g2o::Texture& bar, float percentage, TextureSize textureSize, Int x, Int y)
	{
		const auto width = std::floorf(textureSize.first * percentage);
		const auto deltaWidth = textureSize.first - width;

		bar.setUV(1.f - percentage, 0.f, percentage, 1.f);
		bar.setSize(C_F->anx(width), C_F->any(textureSize.second));
		bar.setPosition(x + C_F->anx(deltaWidth), y);
	}


	void HUD::draw(const float deltaTime)
	{
		drawHp(deltaTime);
		drawMp(deltaTime);
		drawStamina(deltaTime);
	}

	void HUD::drawHp(float deltaTime)
	{
		static bool isUpdateNeeded{ true };
		static int previousHp{ 0 };
		static float time{ 0.f };

		const int hpMax = C_F->getPlayerMaxHealth(ClientConstants::heroId);

		if (hpMax <= 0) return;

		int hp = C_F->getPlayerHealth(ClientConstants::heroId);
		hp = std::clamp(hp, 0, hpMax);

		if (previousHp != hp)
		{
			isUpdateNeeded = true;
			time = 0.f;
			previousHp = hp;
		}

		if (!isUpdateNeeded) return;

		const float hpPercentage = static_cast<float>(hp) / static_cast<float>(hpMax);
		static float hpPercentageRender{ 0.f };

		if (hpPercentageRender != hpPercentage)
		{
			hpPercentageRender = std::lerp(hpPercentageRender, hpPercentage, time);
			hpPercentageRender = std::clamp(hpPercentageRender, 0.f, 1.f);
			time += 1.f * deltaTime;
		}
		else
		{
			isUpdateNeeded = false;
		}

		processHorizontalBar(healthBarFull, hpPercentageRender, TEXTURE_BAR);
	}

	void HUD::drawMp(float deltaTime)
	{
		static bool isUpdateNeeded{ true };
		static int previousMp{ 0 };
		static float time{ 0.f };
		const int mpMax = C_F->getPlayerMaxMana(ClientConstants::heroId);

		if (mpMax <= 0) return;

		int mp = C_F->getPlayerMana(ClientConstants::heroId);

		mp = std::clamp(mp, 0, mpMax);

		if (previousMp != mp)
		{
			isUpdateNeeded = true;
			time = 0.f;
			previousMp = mp;
		}

		if (!isUpdateNeeded) return;

		const float mpPercentage = static_cast<float>(mp) / static_cast<float>(mpMax);

		static float mpPercentageRender{ 0.f };


		if (mpPercentageRender != mpPercentage)
		{
			mpPercentageRender = std::lerp(mpPercentageRender, mpPercentage, time);
			mpPercentageRender = std::clamp(mpPercentageRender, 0.f, 1.f);
			time += 1.f * deltaTime;
		}
		else
		{
			isUpdateNeeded = false;
		}

		const auto pos = manaBarEmpty.getPosition();

		processHorizontalBarMirrored(
			manaBarFull,
			mpPercentageRender,
			TEXTURE_BAR,
			pos.x,
			pos.y);
	}

	void HUD::drawStamina(float deltaTime)
	{
		static float animationTimer{ 0.f };
		static float smoothTimer{ 0.f };

		const auto sprint = Sprint::get();

		const float stamina = sprint->getStamina();
		const float staminaMax = sprint->getStaminaMax();

		if (staminaMax <= 0.f) return;

		const bool isExhausted = sprint->isExhausted();
		const float percentage = stamina / staminaMax;

		if (!isExhausted)
		{
			sprintBarExhausted.visible = false;
			sprintBarFull.visible = true;
			processHorizontalBar(sprintBarFull, percentage, TEXTURE_SPRINT);
		}
		else
		{
			animationTimer += deltaTime;
			float ignore;
			if (animationTimer > 1.f) animationTimer = std::modf(animationTimer, &ignore);

			sprintBarExhausted.visible = true;
			sprintBarFull.visible = false;

			sprintBarExhausted.alpha = std::clamp<Int>(
				std::fabs(animationTimer) * 255.f,
				0,
				255);
		}
	}

	HUD::HUD() :
		healthBarEmpty(
			Virt(0.f),
			Virt(1.f) - C_F->any(TEXTURE_BAR.second),
			C_F->anx(TEXTURE_BAR.first),
			C_F->any(TEXTURE_BAR.second),
			"WOG_HP_BAR_EMPTY.TGA"),

		healthBarFull(
			Virt(0.f),
			Virt(1.f) - C_F->any(TEXTURE_BAR.second),
			C_F->anx(TEXTURE_BAR.first),
			C_F->any(TEXTURE_BAR.second),
			"WOG_HP_BAR_FULL.TGA"),

		manaBarEmpty(
			Virt(1.f) - C_F->anx(TEXTURE_BAR.first),
			Virt(1.f) - C_F->any(TEXTURE_BAR.second),
			C_F->anx(TEXTURE_BAR.first),
			C_F->any(TEXTURE_BAR.second),
			"WOG_MP_BAR_EMPTY.TGA"),

		manaBarFull(
			Virt(1.f) - C_F->anx(TEXTURE_BAR.first),
			Virt(1.f) - C_F->any(TEXTURE_BAR.second),
			C_F->anx(TEXTURE_BAR.first),
			C_F->any(TEXTURE_BAR.second),
			"WOG_MP_BAR_FULL.TGA"),

		sprintBarEmpty(
			Virt(0.5f) - C_F->anx(TEXTURE_SPRINT.first * .5f),
			Virt(1.f) - C_F->any(TEXTURE_SPRINT.second * 2.5f),
			C_F->anx(TEXTURE_SPRINT.first),
			C_F->any(TEXTURE_SPRINT.second),
			"WOG_SPRINT_BAR_EMPTY.TGA"),

		sprintBarExhausted(
			Virt(0.5f) - C_F->anx(TEXTURE_SPRINT.first * .5f),
			Virt(1.f) - C_F->any(TEXTURE_SPRINT.second * 2.5f),
			C_F->anx(TEXTURE_SPRINT.first),
			C_F->any(TEXTURE_SPRINT.second),
			"WOG_SPRINT_BAR_EXHAUSTED.TGA"),

		sprintBarFull(
			Virt(0.5f) - C_F->anx(TEXTURE_SPRINT.first * .5f),
			Virt(1.f) - C_F->any(TEXTURE_SPRINT.second * 2.5f),
			C_F->anx(TEXTURE_SPRINT.first),
			C_F->any(TEXTURE_SPRINT.second),
			"WOG_SPRINT_BAR_FULL.TGA")
	{
		C_F->setHudMode(ClientConstants::HUD_ALL, ClientConstants::HUD_MODE_HIDDEN);
		healthBarEmpty.visible = true;
		healthBarFull.visible = true;

		manaBarEmpty.visible = true;
		manaBarFull.visible = true;

		sprintBarEmpty.visible = true;
		sprintBarFull.visible = true;

		//healthBarEmpty.setUV(0.f, uvBias, 1.f - uvBias, 1.f);
		//manaBarEmpty.setUV(0.f, uvBias, 1.f - uvBias, 1.f);

		nonut::g2o::ClientEventHandlers::onRenderHandler.emplace_back(
			[this](Float deltaTime)
			{
				draw(deltaTime);
			});
	}
}
