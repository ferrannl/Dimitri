#include "ObjectFactory.h"
#include "../Models/Wall.h"
#include "../Models/Player.h"
#include "../Models/Switch.h"
#include "../Models/Lamp.h"
#include "../Models/LightBeam.h"

using namespace Game;

std::shared_ptr<Models::IObject> Factories::ObjectFactory::create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width, Game::Enums::StateEnum state)
{
	std::shared_ptr<Models::IObject> instance;

	switch (type) {
	case Enums::TypeEnum::FLOOR:
		instance.reset(new Models::Wall{ x,y,z,height,width,state });
		break;
	case Enums::TypeEnum::LEVER:
		instance.reset(new Models::Switch{ x,y,z,height,width,state });
		break;
	case Enums::TypeEnum::PLAYER:
		instance.reset(new Models::Player{ x, y, z, height, width, state });
		break;
	case Enums::TypeEnum::LAMP:
		instance.reset(new Models::Lamp{x, y, z, height, width, state});
		break;
	case Enums::TypeEnum::BEAM:
		instance.reset(new Models::LightBeam{ x,y,z,height,width,state });
		break;
	}

	return instance;
 }
