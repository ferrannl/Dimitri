#include "StartButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager) :
			Button(x, y, z, height, width, state, scene_height, "StartButton")
		{
			_level_manager = level_manager;
		}

		void Game::Models::Buttons::StartButton::interact()
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
