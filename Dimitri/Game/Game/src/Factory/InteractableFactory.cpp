#include "InteractableFactory.h"
#include "../Models/Wall.h"
#include "../Models/Player.h"
#include "../Models/Switch.h"

using namespace Game;

Game::Factories::InteractableFactory::InteractableFactory()
{

}

std::shared_ptr<Models::IInteractable> Factories::InteractableFactory::create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width)
{
	std::shared_ptr<Models::IInteractable> instance;

	switch (type) {
	case Enums::TypeEnum::LEVER:
		instance.reset(new Models::Switch{ x,y,z,height,width,Game::Enums::StateEnum::RIGHT });
		break;
	}
	return instance;
}
