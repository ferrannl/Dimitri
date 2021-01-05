#include "OpenWinLevelViewCommand.h"

namespace Game {
	namespace Commands {
		OpenWinLevelViewCommand::OpenWinLevelViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void OpenWinLevelViewCommand::execute(int param)
		{
			auto w_ctrl = _main_controller->get_window_controller();
			_main_controller->get_settings()->set_unlocked_level(_main_controller->get_settings()->get_unlocked_level()+1);
			_main_controller->get_highscore()->add_highscore(_main_controller->get_settings()->get_current_level(), std::to_string(_main_controller->get_window_controller()->get_graphics_controller()->get_window()->get_timer()->getTicks() / 1000.f));
			w_ctrl->open_view(Enums::ViewEnum::WIN_LEVEL);
		}
	}
}
