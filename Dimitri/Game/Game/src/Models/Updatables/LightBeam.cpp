#include "LightBeam.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::LightBeam::LightBeam(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center, Game::Enums::TypeEnum type) : Models::Updatable(x, y, z, height, width, state, center, type)
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::LightBeam::set_angle(int speed)
{
	_angle *= speed;
}

void Models::LightBeam::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lightbeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));
	get_texture()->set_visible(true);
}

void Game::Models::LightBeam::update_object(Controllers::LevelController* ctrl)
{
	if (_shape->check_triangle_collision(ctrl->get_level()->get_player()->get_shape()) && get_texture()->is_visible()) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}
}