#include "ClearViewsCommand.h"

namespace Game {
	namespace Commands {
		ClearViewsCommand::ClearViewsCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void ClearViewsCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->clear_views();
		}
	}
}
