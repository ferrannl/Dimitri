#include "Camera.h"

using namespace Game;

Models::Camera::Camera(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Object(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Camera::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/camera.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));
	get_texture()->set_visible(true);
}