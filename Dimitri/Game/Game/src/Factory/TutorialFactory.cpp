#include "TutorialFactory.h"
#include <src/Helpers/BasePathHelper.h>

std::shared_ptr<Graphics::Models::Sprite> Game::Factories::TutorialFactory::create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state)
{
	std::shared_ptr<Graphics::Models::Sprite> instance;

	switch (type) {
	case Enums::TypeEnum::TUT1:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut1.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT2:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut2.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT3:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut3.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT4:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut4.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT5:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut5.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT6:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut6.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT7:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut7.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT8:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut8.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	case Enums::TypeEnum::TUT9:
		instance.reset(new Graphics::Models::Sprite{ x, y, z, height, width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/tutorial/tut9.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{0,0}, true });
		break;
	}

	return instance;
}
