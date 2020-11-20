#include "LightBeam.h"

Game::Models::LightBeam::LightBeam(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::LightBeam::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lightbeam.png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}
