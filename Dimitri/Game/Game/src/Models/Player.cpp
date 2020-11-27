#include "Player.h"

Game::Models::Player::Player(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	_jumps = _max_amount_of_jumps;
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Player::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" }, Graphics::Enums::FlipEnum::NONE, false));
	add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/player_idle_000.png" },  Graphics::Enums::FlipEnum::HORIZONTAL, false));
	get_texture()->set_visible(true);
}

bool Game::Models::Player::jump()
{
	if (_jumps > 0) {
		_jumps--;
		return true;
	}
	else {
		return false;
	}
}

void Game::Models::Player::reset_jump()
{
	_jumps = _max_amount_of_jumps;
}

void Game::Models::Player::set_jumps(int jumps)
{
	_max_amount_of_jumps = jumps;
	if (_jumps > _max_amount_of_jumps) {
		_jumps = jumps;
	}
}
