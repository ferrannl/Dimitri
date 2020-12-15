#include "SetCheatInfiniteCommand.h"

Game::Commands::SetCheatInfiniteCommand::SetCheatInfiniteCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller)
{
}

void Game::Commands::SetCheatInfiniteCommand::execute()
{
	auto c_settings = _main_controller->get_cheats_controller()->get_cheat_settings();
	c_settings->set_amount_of_jumps();
}
