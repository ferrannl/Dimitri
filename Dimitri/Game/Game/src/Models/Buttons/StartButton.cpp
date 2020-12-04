#include "StartButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::StartButton::StartButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, std::shared_ptr<Managers::LevelManager> level_manager, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "StartButton")
		{
			_level_manager = level_manager;
		}

		void Game::Models::Buttons::StartButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
