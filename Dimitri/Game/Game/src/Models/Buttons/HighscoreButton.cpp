#include "HighscoreButton.h"

Game::Models::Buttons::HighscoreButton::HighscoreButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::HighscoreManager> highscore_manager) : Game::Models::Button(x, y, z, height, width, state, scene_height)
{
	_highscore_manager = highscore_manager;
}

void Game::Models::Buttons::HighscoreButton::interact()
{
	_highscore_manager->load_highscore();
}
