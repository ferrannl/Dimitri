#include "CameraBeam.h"
#include "../../Controllers/LevelController.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Game;

Models::CameraBeam::CameraBeam(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center), _angle{0.1}
{
	_angle = 1;

	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::CameraBeam::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/camerabeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));

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

	if (checkcollision(ctrl->get_level()->get_player())) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}

	get_texture()->set_angle(get_texture()->get_angle() + _angle);
}
 
bool Game::Models::CameraBeam::checkcollision(std::shared_ptr<Models::Object> object)
{
	double DEGREES_TO_RADIANS = (double)(M_PI / 180);

	int originx = _x + (_shape->get_width() / 2);
	int originy = _y + (_shape->get_height() / 2);

	int x1 = _x;
	int y1 = _y;
	int x2 = _x + _width;
	int y2 = _y;
	int x3 = _x;
	int y3 = _y + _height;
	int x4 = _x + _width;
	int y4 = _y + _height;

	// 1 translate to center
	x1 -= originx;
	y1 -= originy;
	x2 -= originx;
	y2 -= originy;
	x3 -= originx;
	y3 -= originy;
	x4 -= originx;
	y4 -= originy;

	// 2 rotate
	double radian = DEGREES_TO_RADIANS * get_texture()->get_angle();
	float x1r = cos(radian) * x1 - sin(radian) * y1 + originx;
	float y1r = sin(radian) * x1 + cos(radian) * y1 + originy;
	float x2r = cos(radian) * x2 - sin(radian) * y2 + originx;
	float y2r = sin(radian) * x2 + cos(radian) * y2 + originy;
	float x3r = cos(radian) * x3 - sin(radian) * y3 + originx;
	float y3r = sin(radian) * x3 + cos(radian) * y3 + originy;
	float x4r = cos(radian) * x4 - sin(radian) * y4 + originx;
	float y4r = sin(radian) * x4 + cos(radian) * y4 + originy;
	
	// 3 translate back
	return false;
}