#ifndef WOG_CLIENT_HUD_H
#define WOG_CLIENT_HUD_H
#include "pch.h"
#include "class/ui/Texture.h"

namespace wog
{
	class HUD
	{
	public:
		static HUD* get();

		void draw(float deltaTime);
		void drawHp(float deltaTime);
		void drawMp(float deltaTime);
		void drawStamina(float deltaTime);

	private:
		static inline HUD* instance = nullptr;
		HUD();
		nonut::g2o::Texture healthBarEmpty;
		nonut::g2o::Texture healthBarFull;

		nonut::g2o::Texture manaBarEmpty;
		nonut::g2o::Texture manaBarFull;

		nonut::g2o::Texture sprintBarEmpty;
		nonut::g2o::Texture sprintBarExhausted;
		nonut::g2o::Texture sprintBarFull;
	};
}
#endif // WOG_CLIENT_HUD_H
