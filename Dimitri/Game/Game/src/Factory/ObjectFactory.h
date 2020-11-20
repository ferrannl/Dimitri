#pragma once
#include "../Models/IObject.h"
#include "../Enums/TypeEnum.cpp"

namespace Game {
	namespace Factories {
		class ObjectFactory {
		public:
			std::shared_ptr<Models::IObject> create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
		};
	}
}