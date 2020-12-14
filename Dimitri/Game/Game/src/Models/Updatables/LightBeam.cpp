#include "LightBeam.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::LightBeam::LightBeam(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::LightBeam::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lightbeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center, true));
	get_texture()->set_visible(true);
}

void Game::Models::LightBeam::update_object(Controllers::LevelController* ctrl)
{
	if (!ctrl->get_cheats_settings()->get_invincible()) {
		if (_shape->check_triangle_collision(ctrl->get_level()->get_player()->get_shape()) && get_texture()->is_visible()) {
			ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
		}
	}
}