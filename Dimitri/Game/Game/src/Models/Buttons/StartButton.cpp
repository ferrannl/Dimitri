#include "StartButton.h"

Game::Models::Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager, Graphics::Models::Center center) : Game::Models::Button(x,y,z,height,width,state,scene_height,center)
{
	_level_manager = level_manager;
}

void Game::Models::Buttons::StartButton::interact(Controllers::LevelController* ctrl)
{
	_level_manager->load_level();
}
