#include "LoadLevelCommand.h"

namespace Game {
	namespace Commands {
		LoadLevelCommand::LoadLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void LoadLevelCommand::execute()
		{
			auto l_mgr = _main_controller->get_level_manager();
			auto a_ctrl = _main_controller->get_audio_controller();
			auto c_ctrl = _main_controller->get_cheats_controller();
			auto l_ctrl = _main_controller->get_level_controller();
			l_ctrl->update_cheats(c_ctrl->get_cheat_settings());
			a_ctrl->pause_audio("homescreen1");
			l_mgr->load_level();
		}
	}
}
