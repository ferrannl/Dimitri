#pragma once
#include <src/Models/Sprite.h>
#include "../interfaces/IFactory.h"

namespace Game {
	namespace Factories {
		class BackgroundFactory : public Interfaces::IFactory<Graphics::Models::Sprite> {
		public:
			std::shared_ptr<Graphics::Models::Sprite> create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Enums::StateEnum state);
		};
	}
}