#include "InteractableFactory.h"
#include "../Models/Wall.h"
#include "../Models/Player.h"
#include "../Models/Switch.h"
#include "../Models/Car.h"
#include "../Enums/TypeEnum.cpp"

using namespace Game;

std::shared_ptr<Models::IInteractable> Factories::InteractableFactory::create(Enums::TypeEnum type, int x, int y, int z, int height, int width)
{
	std::shared_ptr<Models::IInteractable> instance;

	switch (type) {
	case Enums::TypeEnum::LEVER:
		instance.reset(new Models::Switch{ x,y,z,height,width, Enums::StateEnum::RIGHT });
		break;
	case Enums::TypeEnum::CAR:
		instance.reset(new Models::Car{ x,y,z,height,width, Enums::StateEnum::VERTICAL });
		break;
	}

	return instance;
}
