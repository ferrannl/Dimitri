#include "OpenSaveGameViewCommand.h"

namespace Game {
	namespace Commands {
		OpenSaveGameViewCommand::OpenSaveGameViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenSaveGameViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto h_ctrl = _main_controller->get_home_controller();
			auto save_game_ctrl = _main_controller->get_save_game_controller();
			if (!w_ctrl->is_active(Enums::ViewEnum::SAVE_GAME)) {
				i_ctrl->unsubscribe(h_ctrl);
				w_ctrl->clear_views();
				w_ctrl->open_view(Enums::ViewEnum::SAVE_GAME);
				w_ctrl->open_view(Enums::ViewEnum::FPS);
				l_ctrl->stop();
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->subscribe(save_game_ctrl);
			}
		}
	}
}
