#include "Spike.h"
#include "../../Enums/LevelStateEnum.cpp"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::Spike::Spike(int x, int y, int z, int height, int width, Enums::StateEnum state, Graphics::Models::Center center) : Models::Updatable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, false, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Spike::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/spike.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	get_texture()->set_visible(true);
}

void Game::Models::Spike::update(Controllers::LevelController* ctrl)
{
	if (ctrl->get_level()->get_player()->get_y() <= (_y + _height))
		ctrl->notify(Enums::LevelStateEnum::GAME_OVER);
}