#include "PlayerMoveLeftCommand.h"

namespace Game {
	namespace Commands {
		PlayerMoveLeftCommand::PlayerMoveLeftCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PlayerMoveLeftCommand::execute()
		{
			auto state = _main_controller->get_level_controller()->get_state();
			auto player = _main_controller->get_level_controller()->get_level()->get_player();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				player->set_state(Game::Enums::StateEnum::LEFT);
				player->get_shape()->move_x(-1);
			}
		}
	}
}
