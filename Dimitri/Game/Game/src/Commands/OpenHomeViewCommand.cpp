#include "OpenHomeViewCommand.h"

namespace Game {
	namespace Commands {
		OpenHomeViewCommand::OpenHomeViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenHomeViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto a_ctrl = _main_controller->get_audio_controller();
			auto h_ctrl = _main_controller->get_home_controller();
			auto save_game_ctrl = _main_controller->get_save_game_controller();
			auto c_ctrl = _main_controller->get_credits_controller();
			auto cheats_ctrl = _main_controller->get_cheats_controller();
			auto help_ctrl = _main_controller->get_help_controller();
			auto h_mgr = _main_controller->get_highscore_manager();
			auto level_selector_ctrl = _main_controller->get_level_selector_controller();
			if (!w_ctrl->is_active(Enums::ViewEnum::HOME)) {
				
				if (l_ctrl->get_level()) {
					l_ctrl->stop();
					sleep_for(10ms);
					l_ctrl->clear_level();
				}
				i_ctrl->unsubscribe(l_ctrl);
				i_ctrl->unsubscribe(c_ctrl);
				i_ctrl->unsubscribe(save_game_ctrl);
				i_ctrl->unsubscribe(level_selector_ctrl);
				i_ctrl->unsubscribe(help_ctrl);
				i_ctrl->unsubscribe(h_mgr);
				i_ctrl->unsubscribe(cheats_ctrl);
				i_ctrl->subscribe(h_ctrl);

				w_ctrl->clear_views();
				w_ctrl->open_view(Enums::ViewEnum::HOME);
				w_ctrl->open_view(Enums::ViewEnum::ADVERTISEMENT);
				w_ctrl->open_view(Enums::ViewEnum::FPS);
				
				if (!a_ctrl->is_playing("homescreen1")) {
					a_ctrl->play_audio("homescreen1");
				}
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
			}
		}
	}
}
