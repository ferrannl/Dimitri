#include "Player.h"

Game::Models::Player::Player(int x, int y, int z, int height, int width) : Game::Models::IObject(x, y, z, height, width)
{
	initialize_textures();
}

void Game::Models::Player::initialize_textures()
{
	_state = "right";
	add_texture("right", std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" },  Graphics::Enums::FlipEnum::NONE));
	add_texture("left", std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" },  Graphics::Enums::FlipEnum::HORIZONTAL));
}
