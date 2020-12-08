#include "StartButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "StartButton", Game::Enums::ButtonEnum::START)
		{
			initialize_textures();
			_level_manager = level_manager;
		}

		void Game::Models::Buttons::StartButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
