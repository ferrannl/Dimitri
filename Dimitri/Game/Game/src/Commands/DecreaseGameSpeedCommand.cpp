#include "DecreaseGameSpeedCommand.h"
#include <stdlib.h>

namespace Game {
	namespace Commands {
		DecreaseGameSpeedCommand::DecreaseGameSpeedCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void DecreaseGameSpeedCommand::execute()
		{
			float speed = _main_controller->get_level_controller()->get_speed();
			if (speed > 1)
			{
				_main_controller->get_level_controller()->set_speed(speed -= 0.5);
			}
		}
	}
}