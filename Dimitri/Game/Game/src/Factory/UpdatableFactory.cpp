#include "UpdatableFactory.h"
#include "../Models/Updatables/Player.h"
#include "../Models/Updatables/Spike.h"
#include "../Models/Updatables/LightBeam.h"
#include "../Models/Updatables/CameraBeam.h"

#include "../Enums/TypeEnum.cpp"

using namespace Game;

std::shared_ptr<Models::Updatable> Factories::UpdatableFactory::create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::DirectionEnum state, int val)
{
	std::shared_ptr<Models::Updatable> instance;

	switch (type) {
	case Enums::TypeEnum::SPIKE:
		instance.reset(new Models::Spike{ x,y,z,height,width, state, Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::BEAM:
		instance.reset(new Models::LightBeam{ x,y,z,height,width,state, Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::CAM_VISION:
		Models::CameraBeam* beam = new Models::CameraBeam{ x,y,z,height,width,state , Graphics::Models::Center{width / 2,0} };
		beam->set_bounds(val);
		instance.reset(beam);
		break;
	}

	return instance;
}

