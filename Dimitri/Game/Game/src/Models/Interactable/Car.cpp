#include "Car.h"
#include "../../Controllers/LevelController.h"

using namespace Game;

Models::Car::Car(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Interactable(x, y, z, height, width, state, center)
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Models::Car::initialize_textures()
{
	switch (this->_direction) {
	case Enums::DirectionEnum::LEFT:
		_animatestate = Enums::AnimateEnum::IDLE1;
		add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/car.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
		break;
	case Enums::DirectionEnum::RIGHT:
		_animatestate = Enums::AnimateEnum::IDLE2;
		add_texture(Enums::AnimateEnum::IDLE2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/car.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false, _center, true));
		break;
	}

	get_texture()->set_visible(true);
}

void Game::Models::Car::interact(Controllers::LevelController* ctrl)
{
	ctrl->get_level()->play_music("win");
	ctrl->set_state(Enums::LevelStateEnum::WIN);
	ctrl->update_highscore();
}