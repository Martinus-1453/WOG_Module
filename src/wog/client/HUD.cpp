#include "HUD.h"

#include <algorithm>

#include "constant/ClientConstants.h"
#include "function/ClientFunctions.h"
#include "Virt.h"
#include "event/ClientEventHandlers.h"

using ClientConstants = nonut::g2o::ClientConstants;
using Virt = nonut::g2o::Virt;
using TextureSize = std::pair<float, float>;

constexpr auto scale = 0.65f;
constexpr TextureSize TEXTURE_BAR{316.f * scale, 128.f * scale};

constexpr auto uvBias = 0.004f;

namespace wog
{
	HUD* HUD::get()
	{
		if(instance == nullptr)
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

	void processHorizontalBar(nonut::g2o::Texture& bar, float percentage)
	{
		const auto width = std::floorf(TEXTURE_BAR.first * percentage);

		bar.setUV(0.f, 0.f, percentage, 1.f);
		bar.setSize(C_F->anx(width), C_F->any(TEXTURE_BAR.second));
	}

	void processHorizontalBarMirrored(nonut::g2o::Texture& bar, float percentage, Int x, Int y)
	{
		const auto width = std::floorf(TEXTURE_BAR.first * percentage);
		const auto deltaWidth = TEXTURE_BAR.first - width;

		bar.setUV(1.f - percentage, 0.f, percentage, 1.f);
		bar.setSize(C_F->anx(width), C_F->any(TEXTURE_BAR.second));
		bar.setPosition(x + C_F->anx(deltaWidth), y);
	}

	void HUD::refresh(float deltaTime)
	{
		static int previousHp{0};
		static int previousMp{0};
		static float timeHp{ 0.f };
		static float timeMp{ 0.f };
		const int hpMax = C_F->getPlayerMaxHealth(ClientConstants::heroId);
		const int mpMax = C_F->getPlayerMaxMana(ClientConstants::heroId);

		if (hpMax <= 0 || mpMax <= 0)
			return;

		int hp = C_F->getPlayerHealth(ClientConstants::heroId);
		int mp = C_F->getPlayerMana(ClientConstants::heroId);

		hp = std::clamp(hp, 0, hpMax);
		mp = std::clamp(mp, 0, mpMax);

		if (previousHp != hp)
		{
			timeHp = 0.f;
			previousHp = hp;
		}

		if (previousMp != mp)
		{
			timeMp = 0.f;
			previousMp = mp;
		}

		const float hpPercentage = static_cast<float>(hp) / static_cast<float>(hpMax);
		const float mpPercentage = static_cast<float>(mp) / static_cast<float>(mpMax);

		static float hpPercentageRender{0.f};
		static float mpPercentageRender{0.f};


		if (hpPercentageRender != hpPercentage)
		{
			hpPercentageRender = std::lerp(hpPercentageRender,hpPercentage, timeHp);
			hpPercentageRender = std::clamp(hpPercentageRender, 0.f, 1.f);
			timeHp += 1.3f * deltaTime;
		}

		if (mpPercentageRender != mpPercentage)
		{
			mpPercentageRender = std::lerp(mpPercentageRender, mpPercentage, timeHp);
			mpPercentageRender = std::clamp(mpPercentageRender, 0.f, 1.f);
			timeHp += 1.3f * deltaTime;
		}

		processHorizontalBar(healthBarFull, hpPercentageRender);

		processHorizontalBarMirrored(
			manaBarFull, 
			mpPercentageRender,
			Virt(1.f) - C_F->anx(TEXTURE_BAR.first),
			Virt(1.f) - C_F->any(TEXTURE_BAR.second));
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
			"WOG_MP_BAR_FULL.TGA")
	{
		C_F->setHudMode(ClientConstants::HUD_ALL, ClientConstants::HUD_MODE_HIDDEN);
		healthBarEmpty.visible = true;
		healthBarFull.visible = true;
		manaBarEmpty.visible = true;
		manaBarFull.visible = true;

		healthBarEmpty.setUV(0.f, uvBias, 1.f - uvBias, 1.f);
		manaBarEmpty.setUV(0.f, uvBias, 1.f - uvBias, 1.f);

		nonut::g2o::ClientEventHandlers::onRenderHandler.emplace_back(
			[this](float deltaTime)
			{
				refresh(deltaTime);
			});
	}
}
