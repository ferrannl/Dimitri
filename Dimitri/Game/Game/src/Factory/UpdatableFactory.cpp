#include "UpdatableFactory.h"
#include "../Models/Updatables/Player.h"
#include "../Models/Updatables/Spike.h"
#include "../Models/Updatables/LightBeam.h"
#include "../Models/Updatables/CameraBeam.h"
#include "../Enums/TypeEnum.h"

using namespace Game;

std::shared_ptr<Models::Updatable> Factories::UpdatableFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state, float val, bool val2)
{
	std::shared_ptr<Models::Updatable> instance;

	if (type == Enums::TypeEnum::SPIKE) {
		instance.reset(new Models::Spike{ x,y,z,height,width, state, Graphics::Models::Center{0,0} });

	}
	else if (type == Enums::TypeEnum::BEAM) {
		Models::LightBeam* lbeam = new Models::LightBeam{ x,y,z,height,width,state , Graphics::Models::Center{width / 2,0} };
		lbeam->get_texture()->set_visible(val2);
		instance.reset(lbeam);
	}
	else if (type == Enums::TypeEnum::CAM_VISION) {
		Models::CameraBeam* beam = new Models::CameraBeam{ x,y,z,height,width,state , Graphics::Models::Center{width / 2,0} };
		beam->set_bounds(val);
		instance.reset(beam);
	}

	return instance;
}
