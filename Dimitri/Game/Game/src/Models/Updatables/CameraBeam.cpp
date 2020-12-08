#include "CameraBeam.h"
#include "../../Controllers/LevelController.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Game;



Models::CameraBeam::CameraBeam(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	_angle = -1;

	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::CameraBeam::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/camerabeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center, true));

	get_texture()->set_visible(true);
}

void Game::Models::CameraBeam::update_object(Controllers::LevelController* ctrl)
{
	if (get_texture()->get_angle() < -50) {
		_angle *= -1;
	}
	else if (get_texture()->get_angle() > 50) {
		_angle *= -1;
	}

	get_texture()->set_angle(get_texture()->get_angle() + _angle);

	_shape->set_angle(get_texture()->get_angle());

	if (_shape->check_triangle_collision(ctrl->get_level()->get_player()->get_shape())) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}
}