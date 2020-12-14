#include "OpenPauseLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenPauseLevelViewCommand::OpenPauseLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenPauseLevelViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->open_view(Enums::ViewEnum::PAUSE_LEVEL);
		}
	}
}
