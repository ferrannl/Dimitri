#include "OpenCreditsViewCommand.h"

namespace Game {
	namespace Commands {
		OpenCreditsViewCommand::OpenCreditsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenCreditsViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto h_ctrl = _main_controller->get_home_controller();
			i_ctrl->unsubscribe(h_ctrl);
			if (!w_ctrl->is_active("credits")) {
				w_ctrl->clear_views();
				w_ctrl->open_view("credits");
				w_ctrl->open_view("fps");
				l_ctrl->stop();
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->unsubscribe(l_ctrl);
			}
		}
	}
}
