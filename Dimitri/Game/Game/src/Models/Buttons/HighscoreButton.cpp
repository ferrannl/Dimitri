#include "HighscoreButton.h"
#include "../../Mediators/CommandMediator.h"

Game::Models::Buttons::HighscoreButton::HighscoreButton(float x, float y, float z, float height, float width, Enums::DirectionEnum state, float scene_height, Graphics::Models::Center center) : Game::Models::Button(x, y, z, height, width, state, scene_height, center, "HighscoreButton", Game::Enums::ButtonEnum::HIGHSCORE)
{
	initialize_textures();
}

void Game::Models::Buttons::HighscoreButton::interact(Controllers::LevelController* ctrl)
{
	Mediators::CommandMediator::instance()->notify(*this, { Input::Enums::EventEnum::KEY_PRESS_LEFT, std::make_tuple(-1,-1) });
}
