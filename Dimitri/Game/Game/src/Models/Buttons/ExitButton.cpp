#include "ExitButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::ExitButton::ExitButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "ExitButton", Game::Enums::ButtonEnum::EXIT) {
			initialize_textures();
		}

		void Buttons::ExitButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
