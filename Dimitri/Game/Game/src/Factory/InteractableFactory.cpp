#include "InteractableFactory.h"
#include "../Models/IObjects/Wall.h"
#include "../Models/Updatables/Player.h"
#include "../Models/Interactable/Switch.h"
#include "../Models/Interactable/Car.h"
#include "../Models/Updatables/Spike.h"
#include "../Enums/TypeEnum.h"

using namespace Game;

std::shared_ptr<Models::Interactable> Factories::InteractableFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state, std::vector<std::tuple<float, float>> lights, bool secret)
{
	std::shared_ptr<Models::Interactable> instance;

	if (type == Enums::TypeEnum::LEVER) {
		Models::Switch* lever = new Models::Switch{ x,y,z,height,width, state, Graphics::Models::Center{0,0} };
		lever->set_light(lights);
		lever->set_secret(secret);
		instance.reset(lever);
	}
	else if (type == Enums::TypeEnum::CAR) {
		instance.reset(new Models::Car{ x,y,z,height,width, state, Graphics::Models::Center{0,0} });
	}

	return instance;
}
