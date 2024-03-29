#include "OpenLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenLevelViewCommand::OpenLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenLevelViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->close_view(Enums::ViewEnum::PAUSE_LEVEL);
			w_ctrl->open_view(Enums::ViewEnum::LEVEL);
			w_ctrl->open_view(Enums::ViewEnum::HUD);
			w_ctrl->open_view(Enums::ViewEnum::TIMER);
			w_ctrl->open_view(Enums::ViewEnum::FPS);
			w_ctrl->open_view(Enums::ViewEnum::GAMEPLAYSPEED);
		}
	}
}
