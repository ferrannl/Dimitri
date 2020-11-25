#include "StartButton.h"
#include "../../Commands/CommandFactory.h"

namespace Game {
	Models::Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager) : 
		Models::Button(x, y, z, height, width, state, scene_height)
	{
		_level_manager = level_manager;
	}

	void Game::Models::Buttons::StartButton::interact()
	{
		Commands::CommandFactory::instance()->get_command("load_level")->execute();
	}
}
