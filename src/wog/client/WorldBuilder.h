#ifndef WOG_CLIENT_WORLDBUILDER_H
#define WOG_CLIENT_WORLDBUILDER_H

namespace wog
{
	class WorldBuilder
	{
	public:
		static WorldBuilder* get();
		void enable(bool enabled);

	private:
		WorldBuilder();

		void move(float deltaTime);
		void rotate(int x, int y);

		static inline WorldBuilder* instance = nullptr;
		
		bool isEnabled{ false };

		static constexpr float MOVEMENT_SPEED = 100.0f;
		static constexpr float ROTATION_SPEED = 300.0f;
	};
}
#endif // WOG_CLIENT_WORLDBUILDER_H
