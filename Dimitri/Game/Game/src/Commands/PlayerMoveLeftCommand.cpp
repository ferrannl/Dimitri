#include "PlayerMoveLeftCommand.h"

namespace Game {
	namespace Commands {
		PlayerMoveLeftCommand::PlayerMoveLeftCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void PlayerMoveLeftCommand::execute(int param)
		{
			auto state = _main_controller->get_level_controller()->get_state();
			auto player = _main_controller->get_level_controller()->get_level()->get_player();
			if (state == Enums::LevelStateEnum::ACTIVE) {
				player->set_direction(Game::Enums::DirectionEnum::LEFT);
				player->get_shape()->move_x(-1, player->get_speed());
			}
		}
	}
}
