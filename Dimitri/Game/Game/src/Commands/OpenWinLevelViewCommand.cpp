#include "OpenWinLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenWinLevelViewCommand::OpenWinLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenWinLevelViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->open_view(Enums::ViewEnum::WIN_LEVEL);
		}
	}
}
