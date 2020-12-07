#include "ExitButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::ExitButton::ExitButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "ExitButton") {}

		void Buttons::ExitButton::interact(Controllers::LevelController* ctrl)
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
		}
	}
}
