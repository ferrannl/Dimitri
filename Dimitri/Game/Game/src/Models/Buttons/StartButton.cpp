#include "StartButton.h"

Game::Models::Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager) : Game::Models::Button(x,y,z,height,width,state,scene_height)
{
	_level_manager = level_manager;
}

void Game::Models::Buttons::StartButton::interact(Controllers::LevelController* ctrl)
{
	_level_manager->load_level();
}
