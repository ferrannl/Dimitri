#include "SetCheatInvincibleCommand.h"

Game::Commands::SetCheatInvincibleCommand::SetCheatInvincibleCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller)
{
}

void Game::Commands::SetCheatInvincibleCommand::execute()
{
	auto c_settings = _main_controller->get_cheats_controller()->get_cheat_settings();
	c_settings->set_invincible();
}
