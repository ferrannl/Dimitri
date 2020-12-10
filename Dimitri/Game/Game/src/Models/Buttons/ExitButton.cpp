#include "ExitButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::ExitButton::ExitButton(const float x, const float y, const float z, const float height, const float width, const Enums::DirectionEnum state, const float scene_height, const Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "ExitButton", Game::Enums::ButtonEnum::EXIT) {
			initialize_textures();
		}

		void Buttons::ExitButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
