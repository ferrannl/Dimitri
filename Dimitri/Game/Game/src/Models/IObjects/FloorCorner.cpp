#include "FloorCorner.h"

Game::Models::FloorCorner::FloorCorner(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Object(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::FloorCorner::initialize_textures()
{
	switch (_direction) {
	case Enums::DirectionEnum::RIGHT:
		_animatestate = Enums::AnimateEnum::IDLE1;
		add_texture(_animatestate, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
		break;
	case Enums::DirectionEnum::LEFT:
		_animatestate = Enums::AnimateEnum::IDLE2;
		add_texture(_animatestate, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false, _center, true));
		break;
	}

	get_texture()->set_visible(true);
}