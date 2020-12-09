#include "DecreaseGameSpeedButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::DecreaseGameSpeedButton::DecreaseGameSpeedButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "DecreaseGameSpeedButton")
		{
		}

		void Game::Models::Buttons::DecreaseGameSpeedButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}