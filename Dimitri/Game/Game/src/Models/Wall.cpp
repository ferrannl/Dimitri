#include "Wall.h"

Game::Models::Wall::Wall(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width , state)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Wall::initialize_textures()
{
	switch (this->_state) {
	case Game::Enums::StateEnum::HORIZONTAL:
		add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground.png" }, Graphics::Enums::FlipEnum::NONE, false));
		break;
	case Game::Enums::StateEnum::VERTICAL:
		add_texture(Game::Enums::StateEnum::VERTICAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/wall.png" }, Graphics::Enums::FlipEnum::NONE, false));
		break;
	case Game::Enums::StateEnum::RIGHT:
		add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::NONE, false));
		break;
	case Game::Enums::StateEnum::LEFT:
		add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false));
		break;
	}

	get_texture()->set_visible(true);
}
