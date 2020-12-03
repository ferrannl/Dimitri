#include "ToggleFpsViewCommand.h"

namespace Game {
	namespace Commands {
		ToggleFpsViewCommand::ToggleFpsViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void ToggleFpsViewCommand::execute()
		{
			auto w_ctrl = _main_controller->get_window_controller();
			w_ctrl->toggle_view_visibility("fps");
		}
	}
}
