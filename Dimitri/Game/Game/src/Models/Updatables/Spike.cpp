#include "Spike.h"
#include "../../Enums/LevelStateEnum.cpp"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::Spike::Spike(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Spike::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/spike.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	get_texture()->set_visible(true);
}

void Game::Models::Spike::update_object(Controllers::LevelController* ctrl)
{
	if (_shape->check_square_collision(ctrl->get_level()->get_player()->get_shape()))
		ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
}