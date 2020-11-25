#include "PauseLevelCommand.h"

namespace Game {
	namespace Commands {
		PauseLevelCommand::PauseLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PauseLevelCommand::execute()
		{
			auto l_ctrl = _main_controller->get_level_controller();
			auto state = l_ctrl->get_state();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				l_ctrl->set_state(Enums::LevelStateEnum::PAUSED);
			}
			else if (state == Enums::LevelStateEnum::PAUSED) {				
				l_ctrl->start();
			}
		}
	}
}
