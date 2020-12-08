#include "IncreaseGameSpeedCommand.h"
#include <stdlib.h>

namespace Game {
	namespace Commands {
		IncreaseGameSpeedCommand::IncreaseGameSpeedCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void IncreaseGameSpeedCommand::execute()
		{
			float speed = _main_controller->get_level_controller()->get_speed();
			if (speed < 2)
			{
				_main_controller->get_level_controller()->set_speed(speed + 0.5);
			}
		}
	}
}