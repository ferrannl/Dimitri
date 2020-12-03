#include "LoadLevelCommand.h"

namespace Game {
	namespace Commands {
		LoadLevelCommand::LoadLevelCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void LoadLevelCommand::execute()
		{
			auto l_mgr = _main_controller->get_level_manager();
			l_mgr->load_level();
		}
	}
}
