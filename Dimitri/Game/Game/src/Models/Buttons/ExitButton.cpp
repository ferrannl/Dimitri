#include "ExitButton.h"
#include "../../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Buttons::ExitButton::ExitButton(int x, int y, int z, int height, int width, Enums::StateEnum state, int scene_height) :
			Button(x, y, z, height, width, state, scene_height, "ExitButton") {}

		void Buttons::ExitButton::interact()
		{
			Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_RIGHT, std::make_tuple(-1,-1) });
		}
	}
}