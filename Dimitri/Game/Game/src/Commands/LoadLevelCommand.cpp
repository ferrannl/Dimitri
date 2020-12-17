#include "LoadLevelCommand.h"

namespace Game {
	namespace Commands {
		LoadLevelCommand::LoadLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void LoadLevelCommand::execute(int param)
		{
			auto l_mgr = _main_controller->get_level_manager();
			auto a_ctrl = _main_controller->get_audio_controller();
			auto c_ctrl = _main_controller->get_cheats_controller();
			auto w_ctrl = _main_controller->get_window_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			auto level_selector_ctrl = _main_controller->get_level_selector_controller();
			i_ctrl->unsubscribe(level_selector_ctrl);
			auto l_ctrl = std::make_shared<Game::Controllers::LevelController>(w_ctrl, a_ctrl);
			i_ctrl->unsubscribe(_main_controller->get_level_controller());
			_main_controller->set_level_controller(l_ctrl);
			_main_controller->get_level_manager()->set_level_controller(l_ctrl);
			if (param <= 0) {
				l_ctrl->setup_level("tutorial");
			}
			else {
				l_ctrl->setup_level("level" + std::to_string(param));
			}
			l_ctrl->load_buttons();
			w_ctrl->set_textures(l_ctrl->get_textures(Enums::LevelStateEnum::ACTIVE), Enums::ViewEnum::LEVEL);
			w_ctrl->add_textures(l_ctrl->get_level()->get_player()->get_extra_textures(), Enums::ViewEnum::HUD);
			w_ctrl->add_textures(l_ctrl->get_textures(Enums::LevelStateEnum::PAUSED), Enums::ViewEnum::PAUSE_LEVEL);
			w_ctrl->add_textures(l_ctrl->get_textures(Enums::LevelStateEnum::GAME_OVER), Enums::ViewEnum::GAME_OVER_LEVEL);
			w_ctrl->add_textures(l_ctrl->get_textures(Enums::LevelStateEnum::WIN), Enums::ViewEnum::WIN_LEVEL);
			l_ctrl->update_cheats(c_ctrl->get_cheat_settings());
			a_ctrl->pause_audio("homescreen1");
			l_mgr->load_level();
		}
	}
}
