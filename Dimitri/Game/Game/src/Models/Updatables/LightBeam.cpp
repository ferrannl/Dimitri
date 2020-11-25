#include "LightBeam.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::LightBeam::LightBeam(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::LightBeam::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lightbeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));
	get_texture()->set_visible(true);
}

void Game::Models::LightBeam::update_object(Controllers::LevelController* ctrl)
{
	if (checkcollision(ctrl->get_level()->get_player()) && get_texture()->is_visible()) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}
}

bool Game::Models::LightBeam::checkcollision(std::shared_ptr<Models::Object> object)
{
	double DEGREES_TO_RADIANS = (double)(M_PI / 180);

	int originx = _x + (_shape->get_width() / 2);
	int originy = _y + (_shape->get_height() / 2);

	int x1 = _x;
	int y1 = _y;
	int x2 = _x + _width;
	int y2 = _y;
	int x3 = _x + (_width / 2);
	int y3 = _y + _height;

	// 1 translate to center
	x1 -= originx;
	y1 -= originy;
	x2 -= originx;
	y2 -= originy;

	// 2 rotate
	double radian = DEGREES_TO_RADIANS * (get_texture()->get_angle() * -1);

	float x1r = (cos(radian) * x1) - (sin(radian) * y1) + originx;
	float y1r = (sin(radian) * x1) + (cos(radian) * y1) + originy;
	float x2r = (cos(radian) * x2) - (sin(radian) * y2) + originx;
	float y2r = (sin(radian) * x2) + (cos(radian) * y2) + originy;

	int playerx = object->get_x() + object->get_width() / 2;
	int playery = object->get_y() + object->get_height() / 2;

	int beam_area = area(x1r, y1r, x2r, y2r, x3, y3);
	int a1 = area(playerx, playery, x2r, y2r, x3, y3);
	int a2 = area(x1r, y1r, playerx, playery, x3, y3);
	int a3 = area(x1r, y1r, x2r, y2r, playerx, playery);

	return (beam_area == a1 + a2 + a3);
}

float Game::Models::LightBeam::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2.0);
}