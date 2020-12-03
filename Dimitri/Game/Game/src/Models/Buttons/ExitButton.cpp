#include "ExitButton.h"

Game::Models::Buttons::ExitButton::ExitButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center) : Game::Models::Button(x, y, z, height, width, state, scene_height, center)
{
}

void Game::Models::Buttons::ExitButton::interact(Controllers::LevelController* ctrl)
{
	exit(0);
}