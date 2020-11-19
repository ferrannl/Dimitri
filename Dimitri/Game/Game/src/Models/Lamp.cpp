#include "Lamp.h"

Game::Models::Lamp::Lamp(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Lamp::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 50, 50, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lamp.png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}
