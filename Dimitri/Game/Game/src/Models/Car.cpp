#include "Car.h"
#include "../Controllers/LevelController.h"

Game::Models::Car::Car(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IInteractable(x, y, z, height, width, state)
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Car::initialize_textures()
{
	switch (this->_state) {
	case Game::Enums::StateEnum::HORIZONTAL:
		add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/car.png" }, Graphics::Enums::FlipEnum::NONE, false));
		break;
	case Game::Enums::StateEnum::VERTICAL:
		add_texture(Game::Enums::StateEnum::VERTICAL, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/car.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false));
		break;
	}

	get_texture()->set_visible(true);
}

void Game::Models::Car::interact(Controllers::LevelController* ctrl)
{
	ctrl->set_state(Enums::LevelStateEnum::WIN);
}
