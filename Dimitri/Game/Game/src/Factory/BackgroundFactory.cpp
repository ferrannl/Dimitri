#include "BackgroundFactory.h"
#include <src/Helpers/BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Enums/TypeEnum.h"
#include "../Enums/StateEnum.h"

using namespace Game;

std::shared_ptr<Graphics::Models::Sprite> Factories::BackgroundFactory::create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Enums::DirectionEnum state)
{
	std::shared_ptr<Graphics::Models::Sprite> instance;

	switch (type) {
	case Enums::TypeEnum::BG:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::BG_TOP1:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/top1.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::BG_TOP2:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/top2.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	}
	return instance;
}