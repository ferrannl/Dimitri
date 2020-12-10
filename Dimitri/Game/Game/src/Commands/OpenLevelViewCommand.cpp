#include "OpenLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenLevelViewCommand::OpenLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenLevelViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->toggle_view_visibility("timer");
			w_ctrl->clear_views();
			w_ctrl->toggle_view_visibility("timer");
			w_ctrl->open_view("level");
			w_ctrl->open_view("timer");
			w_ctrl->open_view("hud_view");
			w_ctrl->open_view("gameplay_speed_view");
			w_ctrl->open_view("fps");
		}
	}
}
