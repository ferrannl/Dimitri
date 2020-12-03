#include "BackgroundFactory.h"
#include <src/Helpers/BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Enums/TypeEnum.cpp"
#include "../Enums/StateEnum.cpp"

using namespace Game;

std::shared_ptr<Graphics::Models::Sprite> Factories::BackgroundFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state)
{
	std::shared_ptr<Graphics::Models::Sprite> instance;

	switch (type) {
	case Enums::TypeEnum::BG:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::BG_TOP1:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/top1.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0} });
		break;
	case Enums::TypeEnum::BG_TOP2:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/top2.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0} });
		break;
	}
	return instance;
}