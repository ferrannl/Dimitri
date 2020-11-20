#include "ObjectFactory.h"
#include "../Models/Wall.h"
#include "../Models/Player.h"
#include "../Models/Switch.h"

using namespace Game;

Game::Factories::ObjectFactory::ObjectFactory()
{
	_objects = {};
}

std::shared_ptr<Models::IObject> Factories::ObjectFactory::create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width, Game::Enums::StateEnum state)
{
	std::shared_ptr<Models::IObject> instance;

	switch (type) {
	case Enums::TypeEnum::FLOOR:
		instance.reset(new Models::Wall{x,y,z,height,width,state});
		break;
	case Enums::TypeEnum::LEVER:
		instance.reset(new Models::Switch{ x,y,z,height,width,state });
		break;
	case Enums::TypeEnum::PLAYER:
		instance = std::make_shared<Models::Player>(Models::Player{ x,y,z,height,width,state });
		break;
	}
	return instance;
 }
