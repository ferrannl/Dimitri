#include "PlayerInteractCommand.h"

namespace Game {
	namespace Commands {
		PlayerInteractCommand::PlayerInteractCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PlayerInteractCommand::execute(int param)
		{
			auto l_ctrl = _main_controller->get_level_controller();
			auto level = l_ctrl->get_level();
			auto state = l_ctrl->get_state();
			auto player = level->get_player();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				for (std::shared_ptr<Models::Interactable> interactable : level->get_interactables())
				{
					if (player->get_shape()->check_square_collision(interactable->get_shape()))
					{
						interactable->interact(l_ctrl.get());
					}
				}
			}
		}
	}
}
