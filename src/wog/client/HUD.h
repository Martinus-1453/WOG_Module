#ifndef WOG_CLIENT_HUD_H
#define WOG_CLIENT_HUD_H
#include "pch.h"
#include "class/Texture.h"

namespace wog
{
	class HUD
	{
	public:
		static HUD* get();

		void refresh(float deltaTime);

	private:
		static inline HUD* instance = nullptr;
		HUD();
		nonut::g2o::Texture healthBarEmpty;
		nonut::g2o::Texture healthBarFull;
		nonut::g2o::Texture manaBarEmpty;
		nonut::g2o::Texture manaBarFull;
	};
}
#endif // WOG_CLIENT_HUD_H
