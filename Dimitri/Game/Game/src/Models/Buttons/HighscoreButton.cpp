#include "HighscoreButton.h"

Game::Models::Buttons::HighscoreButton::HighscoreButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, std::shared_ptr<Managers::HighscoreManager> highscore_manager, Graphics::Models::Center center) : Game::Models::Button(x, y, z, height, width, state, scene_height, center)
{
	_highscore_manager = highscore_manager;
}

void Game::Models::Buttons::HighscoreButton::interact(Controllers::LevelController* ctrl)
{
	_highscore_manager->load_highscore();
}
