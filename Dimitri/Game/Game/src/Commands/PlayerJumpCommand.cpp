#include "PlayerJumpCommand.h"

namespace Game {
	namespace Commands {
		PlayerJumpCommand::PlayerJumpCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PlayerJumpCommand::execute()
		{
			auto state = _main_controller->get_level_controller()->get_state();
			auto player = _main_controller->get_level_controller()->get_level()->get_player();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				if (player->jump()) {
					player->get_shape()->move_y();
				}
			}
		}
	}
}
