#include "StartButton.h"

Game::Models::Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height) : Game::Models::Button(x, y, z, height, width, state, scene_height)
{
}

void Game::Models::Buttons::StartButton::interact()
{
	std::cout << "test123";
}
