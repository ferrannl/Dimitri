#include "Switch.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::Switch::Switch(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Interactable(x, y, z, height, width, state, center), _light_positions{}
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Switch::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false, _center));
	add_texture(Enums::AnimateEnum::IDLE2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	get_texture()->set_visible(true);
}


void Models::Switch::interact(Controllers::LevelController* ctrl)
{
	if (_direction == Enums::DirectionEnum::RIGHT) {
		set_animationstate(Enums::AnimateEnum::IDLE2);
		set_direction(Enums::DirectionEnum::LEFT);
	}
	else {
		set_animationstate(Enums::AnimateEnum::IDLE1);
		set_direction(Enums::DirectionEnum::RIGHT);
	}

	for(std::tuple<int, int> kp : _light_positions) {
		ctrl->toggle_light(kp);
	}
}

void Models::Switch::set_light(const std::tuple<int, int> light_pos)
{
	_light_positions.push_back(light_pos);
}

