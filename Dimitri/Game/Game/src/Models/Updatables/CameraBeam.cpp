#include "CameraBeam.h"

using namespace Game;

Models::CameraBeam::CameraBeam(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center), _angle{0.1}
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::CameraBeam::initialize_textures()
{
	add_texture(Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/camerabeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));

	get_texture()->set_visible(true);
}

void Game::Models::CameraBeam::update(Controllers::LevelController* ctrl)
{
	if (get_texture()->get_angle() < -50) {
		_angle *= -1;
	}
	else if (get_texture()->get_angle() > 50) {
		_angle *= -1;
	}

	get_texture()->set_angle(get_texture()->get_angle() + _angle);
}