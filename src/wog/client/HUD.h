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
		g2o::Texture healthBarEmpty;
		g2o::Texture healthBarFull;

		g2o::Texture manaBarEmpty;
		g2o::Texture manaBarFull;

		g2o::Texture sprintBarEmpty;
		g2o::Texture sprintBarExhausted;
		g2o::Texture sprintBarFull;
	};
}
#endif // WOG_CLIENT_HUD_H
