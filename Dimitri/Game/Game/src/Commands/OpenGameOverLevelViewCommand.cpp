#include "OpenGameOverLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenGameOverLevelViewCommand::OpenGameOverLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenGameOverLevelViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			auto a_ctrl = _main_controller->get_audio_controller();
			a_ctrl->play_audio("failed");
			w_ctrl->open_view(Enums::ViewEnum::GAME_OVER_LEVEL);
		}
	}
}
