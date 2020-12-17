#include "OpenWinLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenWinLevelViewCommand::OpenWinLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenWinLevelViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			_main_controller->get_settings()->set_unlocked_level(_main_controller->get_settings()->get_unlocked_level()+1);
			w_ctrl->open_view(Enums::ViewEnum::WIN_LEVEL);
		}
	}
}
