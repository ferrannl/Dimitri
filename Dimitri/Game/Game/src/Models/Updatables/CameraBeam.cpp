#include "CameraBeam.h"
#include "../../Controllers/LevelController.h"
#define _USE_MATH_DEFINES
#include <math.h>

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

	if (checkcollision(ctrl->get_level()->get_player())) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}

	int originx = _x + (_shape->get_width() / 2);
	int originy = _y + (_shape->get_height() / 2);

	get_texture()->set_angle(get_texture()->get_angle() + _angle);
	std::shared_ptr<Models::Object> tile = ctrl->get_level()->get_tiles().at(0);

		_shape->set_x((originx * cos(_angle)) - (originy * sin(_angle)));
		_shape->set_y((originx * sin(_angle)) + (originy * cos(_angle)));
		tile->set_x((originx * cos(_angle)) - (originy * sin(_angle)));
		tile->set_y((originx * sin(_angle)) + (originy * cos(_angle)));
		tile->get_shape()->set_height(_height);
		tile->get_shape()->set_width(_width);

		tile->get_all_textures().at(0)->set_height(_height);
		tile->get_texture()->set_width(_width);
}

bool Game::Models::CameraBeam::checkcollision(std::shared_ptr<Models::Object> object)
{
		int x = object->get_shape()->get_x() + (object->get_shape()->get_width() / 5);

		return _shape->get_x() - 1 <= x + object->get_shape()->get_width() &&
			_shape->get_x() + _shape->get_width() + 1 >= x &&
			_shape->get_y() - 1 <= object->get_y() + object->get_shape()->get_height() &&
			_shape->get_y() + _shape->get_height() + 1 >= object->get_shape()->get_y();
}