#include "OpenLevelTransitionViewCommand.h"

namespace Game {
	namespace Commands {
		OpenLevelTransitionViewCommand::OpenLevelTransitionViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenLevelTransitionViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->clear_views();
			w_ctrl->open_view(Enums::ViewEnum::LEVEL_TRANSITION);
			w_ctrl->open_view(Enums::ViewEnum::FPS);
		}
	}
}
