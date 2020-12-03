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
	_lights = { 3560, 3240, 1600 };
}

std::shared_ptr<Models::Interactable> Factories::InteractableFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state)
{
	std::shared_ptr<Models::Interactable> instance;
	Models::Switch* lever;
	int last;

	switch (type) {
	case Enums::TypeEnum::LEVER:
		lever = new Models::Switch{ x,y,z,height,width, state, Graphics::Models::Center{0,0} };
		last = _lights.back();
		lever->set_light(last);
		_lights.pop_back();

		instance.reset(lever);
		break;
	case Enums::TypeEnum::CAR:
		instance.reset(new Models::Car{ x,y,z,height,width, state, Graphics::Models::Center{0,0} });
		break;
	}

	return instance;
}
