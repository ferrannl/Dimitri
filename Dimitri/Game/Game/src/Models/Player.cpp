#include "Player.h"

Game::Models::Player::Player(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	initialize_textures();
	create_shape(x, y, height, width, false);
}

void Game::Models::Player::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" },  Graphics::Enums::FlipEnum::NONE));
	add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" },  Graphics::Enums::FlipEnum::HORIZONTAL));
	get_texture()->set_visible(true);
}

void Game::Models::Player::create_shape(int x, int y, int height, int width, bool is_dynamic)
{
	std::unique_ptr<PhysicsCollision::Models::Shape> shape = std::make_unique<PhysicsCollision::Models::Shape>(x, y,  height, width, is_dynamic);
}
