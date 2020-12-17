#include "OpenHelpViewCommand.h"

namespace Game {
	namespace Commands {
		OpenHelpViewCommand::OpenHelpViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenHelpViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto h_ctrl = _main_controller->get_home_controller();
			auto help_ctrl = _main_controller->get_help_controller();
			if (!w_ctrl->is_active(Enums::ViewEnum::HELP)) {
				i_ctrl->unsubscribe(h_ctrl);
				w_ctrl->clear_views();
				w_ctrl->open_view(Enums::ViewEnum::HELP);
				w_ctrl->open_view(Enums::ViewEnum::FPS);				
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());			
				i_ctrl->subscribe(help_ctrl);
			}
		}
	}
}
