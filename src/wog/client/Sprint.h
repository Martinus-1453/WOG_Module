#ifndef WOG_CLIENT_SPRINT_H
#define WOG_CLIENT_SPRINT_H

namespace wog
{
	class Sprint
	{
	public:
		static Sprint* get();
		[[nodiscard]] float getStamina() const;
		[[nodiscard]] float getStaminaMax() const;
		[[nodiscard]] bool isExhausted() const;
	private:
		Sprint();

		void update(float deltaTime);

		static inline Sprint* instance = nullptr;
		//TODO: Replace with fetch from player data
		float stamina{0.f};
		float staminaMax{100.f};
		float staminaRegen{10.f};
		float staminaDrain{40.f};
		bool isActive{false};
		float keyTimer{0.f};
		float exhaustionTimer{0.f};

		static constexpr float KEY_TIMEOUT = 0.3f;
		static constexpr float EXHAUSTION_TIME = 3.f;
	};
}
#endif // WOG_CLIENT_SPRINT_H
