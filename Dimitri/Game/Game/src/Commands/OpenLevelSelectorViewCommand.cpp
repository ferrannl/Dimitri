#include "OpenLevelSelectorViewCommand.h"

namespace Game {
	namespace Commands {
		OpenLevelSelectorViewCommand::OpenLevelSelectorViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenLevelSelectorViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto level_selector_ctrl = _main_controller->get_level_selector_controller();
			if (!w_ctrl->is_active(Enums::ViewEnum::LEVEL_SELECTOR)) {
				w_ctrl->clear_views();
				w_ctrl->open_view(Enums::ViewEnum::LEVEL_SELECTOR);
				w_ctrl->open_view(Enums::ViewEnum::FPS);
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->subscribe(level_selector_ctrl);
			}
		}
	}
}
