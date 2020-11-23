#include "Wall.h"

using namespace Game;

Models::Wall::Wall(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center) : Models::Object(x, y, z, height, width , state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Wall::initialize_textures()
{
	switch (this->_state) {
	case Enums::StateEnum::HORIZONTAL:
		add_texture(Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
		break;
	case Enums::StateEnum::VERTICAL:
		add_texture(Enums::StateEnum::VERTICAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/wall.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
		break;
	case Enums::StateEnum::RIGHT:
		add_texture(Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
		break;
	case Enums::StateEnum::LEFT:
		add_texture(Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false, _center));
		break;
	}

	get_texture()->set_visible(true);
}
