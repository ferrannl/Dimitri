#include "OpenLevelSelectorViewCommand.h"
#include "../Models/Settings/Settings.h";

namespace Game {
	namespace Commands {
		OpenLevelSelectorViewCommand::OpenLevelSelectorViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenLevelSelectorViewCommand::execute(int param)
		{
			if (param != -1) {
				_main_controller->set_settings(std::make_shared<Models::Settings>(param));
			}
			auto w_ctrl = _main_controller->get_window_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto level_selector_ctrl = _main_controller->get_level_selector_controller();
			auto save_game_ctrl = _main_controller->get_save_game_controller();
			if (!w_ctrl->is_active(Enums::ViewEnum::LEVEL_SELECTOR)) {
				i_ctrl->unsubscribe(save_game_ctrl);
				w_ctrl->clear_views();
				w_ctrl->open_view(Enums::ViewEnum::LEVEL_SELECTOR);
				w_ctrl->open_view(Enums::ViewEnum::FPS);
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->subscribe(level_selector_ctrl);
			}
		}
	}
}
