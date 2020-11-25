#include "PauseLevelCommand.h"
#include "CommandFactory.h"

namespace Game {
	namespace Commands {
		PauseLevelCommand::PauseLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PauseLevelCommand::execute()
		{
			auto l_ctrl = _main_controller->get_level_controller();
			auto state = l_ctrl->get_state();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				l_ctrl->set_state(Enums::LevelStateEnum::PAUSED);
				CommandFactory::instance()->get_command("open_pause_level_view")->execute();
			}
			else if (state == Enums::LevelStateEnum::PAUSED) {				
				l_ctrl->start();
			}
		}
	}
}
