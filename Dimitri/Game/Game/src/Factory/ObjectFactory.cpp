#include "ObjectFactory.h"
#include "../Models/Objects/Wall.h"
#include "../Models/Objects/Lamp.h"
#include "../Models/Objects/Camera.h"
#include "../Models/Objects/FloorCorner.h"
#include "../Models/Objects/Floor.h"

using namespace Game;

std::shared_ptr<Models::Object> Factories::ObjectFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state)
{
	std::shared_ptr<Models::Object> instance;

	switch (type) {
	case Enums::TypeEnum::FLOOR:
		instance.reset(new Models::Floor{ x,y,z,height,width,state , Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::CORNER:
		instance.reset(new Models::FloorCorner{ x,y,z,height,width,state , Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::WALL:
		instance.reset(new Models::Wall{ x,y,z,height,width,state , Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::LAMP:
		instance.reset(new Models::Lamp{x, y, z, height, width, state, Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::CAMERA:
		instance.reset(new Models::Camera{ x, y, z, height, width, state , Graphics::Models::Center{0,0} });
		break;
	}

	return instance;
 }
