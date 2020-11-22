#include "InteractableFactory.h"
#include "../Models/Wall.h"
#include "../Models/Player.h"
#include "../Models/Switch.h"
#include "../Models/Car.h"
#include "../Enums/TypeEnum.cpp"

using namespace Game;

Game::Factories::InteractableFactory::InteractableFactory()
{
	_lights = { 3560, 3240, 1600 };
}

std::shared_ptr<Models::IInteractable> Factories::InteractableFactory::create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::StateEnum state)
{
	std::shared_ptr<Models::IInteractable> instance;
	Models::Switch* lever;
	int last;

	switch (type) {
	case Enums::TypeEnum::LEVER:
		lever = new Models::Switch{ x,y,z,height,width, state };
		last = _lights.back();
		lever->set_light(last);
		_lights.pop_back();

		instance.reset(lever);
		break;
	case Enums::TypeEnum::CAR:
		instance.reset(new Models::Car{ x,y,z,height,width, state });
		break;
	}

	return instance;
}
