#include "OpenHighscoreViewCommand.h"

namespace Game {
	namespace Commands {
		Game::Commands::OpenHighscoreViewCommand::OpenHighscoreViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}


		void Game::Commands::OpenHighscoreViewCommand::execute()
		{
			auto l_mgr = _main_controller->get_highscore_manager();
			l_mgr->load_highscore();
		}
	}
}
