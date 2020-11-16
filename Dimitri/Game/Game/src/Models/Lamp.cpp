#include "Lamp.h"

Game::Models::Lamp::Lamp(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IInteractable(x, y, z, height, width, state)
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Polygon);
}

void Game::Models::Lamp::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(0, 0, 1, 100, 100, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/triangle.png" }, Graphics::Enums::FlipEnum::NONE));
	get_texture()->set_visible(true);
}

void Game::Models::Lamp::interact()
{
	if (_state == Game::Enums::StateEnum::LEFT) {
		set_state(Game::Enums::StateEnum::RIGHT);
	}
	else {
		set_state(Game::Enums::StateEnum::LEFT);
	}
}