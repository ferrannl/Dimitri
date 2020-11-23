#include "LightBeam.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::LightBeam::LightBeam(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::LightBeam::initialize_textures()
{
	add_texture(Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/lightbeam.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));
	get_texture()->set_visible(true);
}

void Game::Models::LightBeam::update(Controllers::LevelController* ctrl)
{
	if (_shape->check_polygon_collision(ctrl->get_level()->get_player()->get_shape())) {
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
	}
}
