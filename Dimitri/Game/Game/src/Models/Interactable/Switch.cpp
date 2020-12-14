#include "Switch.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::Switch::Switch(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Interactable(x, y, z, height, width, state, center), _switch_x(x)
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Switch::initialize_textures()
{
	_animatestate = Enums::AnimateEnum::IDLE1;

	add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false, _center, true));
	add_texture(Enums::AnimateEnum::IDLE2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	get_texture()->set_visible(true);
}


void Models::Switch::interact(Controllers::LevelController* ctrl)
{
	if (_direction == Enums::DirectionEnum::RIGHT) {
		set_animationstate(Enums::AnimateEnum::IDLE2);
		set_direction(Enums::DirectionEnum::LEFT);
		ctrl->turn_off_light(_switch_x);
	}
	else {
		set_animationstate(Enums::AnimateEnum::IDLE1);
		set_direction(Enums::DirectionEnum::RIGHT);
	}
}

void Models::Switch::set_light(const float x)
{
	_switch_x = x;
}

