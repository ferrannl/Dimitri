#include "OpenHelpViewCommand.h"

namespace Game {
	namespace Commands {
		OpenHelpViewCommand::OpenHelpViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenHelpViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			if (!w_ctrl->is_active("help") && !w_ctrl->is_active("home")) {
				w_ctrl->clear_views();
				w_ctrl->open_view("help");
				w_ctrl->open_view("fps");
				l_ctrl->stop();
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->unsubscribe(l_ctrl);
			}
		}
	}
}
