#include "InteractableFactory.h"
#include "../Models/IObjects/Wall.h"
#include "../Models/Updatables/Player.h"
#include "../Models/Interactable/Switch.h"
#include "../Models/Interactable/Car.h"
#include "../Models/Updatables/Spike.h"
#include "../Enums/TypeEnum.cpp"

using namespace Game;

Game::Factories::InteractableFactory::InteractableFactory()
{
}

std::shared_ptr<Models::Interactable> Factories::InteractableFactory::create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::DirectionEnum state, int light_x, int light_y)
{
	std::shared_ptr<Models::Interactable> instance;

	if (type == Enums::TypeEnum::LEVER) {
		Models::Switch* lever = new Models::Switch{ x,y,z,height,width, state, Graphics::Models::Center{0,0} };
		lever->set_light(std::make_tuple(light_x, light_y));
		instance.reset(lever);
	}
	else if (type == Enums::TypeEnum::CAR) {
		instance.reset(new Models::Car{ x,y,z,height,width, state, Graphics::Models::Center{0,0} });
	}

	return instance;
}
