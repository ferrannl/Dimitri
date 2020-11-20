#pragma once
#include <memory>
#include "../Enums/TypeEnum.cpp"
#include "../Enums/StateEnum.cpp"
#include <src/Models/Sprite.h>

namespace Game {
	namespace Factories {
		class BackgroundFactory {
		public:
			std::shared_ptr<Graphics::Models::Sprite> create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Game::Enums::StateEnum state);
		};
	}
}