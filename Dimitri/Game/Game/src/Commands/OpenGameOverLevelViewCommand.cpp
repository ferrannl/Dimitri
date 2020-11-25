#include "OpenGameOverLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenGameOverLevelViewCommand::OpenGameOverLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenGameOverLevelViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->open_view("game_over_level");
		}
	}
}
