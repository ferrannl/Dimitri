#include "StartButton.h"

Game::Models::Buttons::StartButton::StartButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, std::shared_ptr<Managers::LevelManager> level_manager, Graphics::Models::Center center) : Game::Models::Button(x,y,z,height,width,state,scene_height,center)
{
	_level_manager = level_manager;
}

void Game::Models::Buttons::StartButton::interact(Controllers::LevelController* ctrl)
{
	_level_manager->load_level();
}
