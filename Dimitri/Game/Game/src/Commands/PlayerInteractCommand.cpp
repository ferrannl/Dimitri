#include "PlayerInteractCommand.h"
#include "CommandFactory.h"

namespace Game {
	namespace Commands {
		PlayerInteractCommand::PlayerInteractCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PlayerInteractCommand::execute()
		{
			auto l_ctrl = _main_controller->get_level_controller();
			auto level = l_ctrl->get_level();
			auto state = l_ctrl->get_state();
			auto player = level->get_player();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				for (std::shared_ptr<Models::IInteractable> interactable : level->get_interactables())
				{
					if (player->get_shape()->check_square_collision(interactable->get_shape()))
					{
						interactable->interact();
					}
				}
				for (std::shared_ptr<Models::IObject> light : level->get_lights())
				{
					if (player->get_shape()->check_polygon_collision(light->get_shape()))
					{
						CommandFactory::instance()->get_command("open_game_over_level_view")->execute();
						l_ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
					}
				}
			}
		}
	}
}
