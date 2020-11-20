#pragma once
#include "IFactory.h"
#include "../Models/IObject.h"

namespace Game {
	namespace Factories {
		class ObjectFactory {
		private:
			std::map<Game::Enums::TypeEnum, Models::IObject*> _objects;
		public:
			ObjectFactory();

			std::shared_ptr<Models::IObject> create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width, Game::Enums::StateEnum state);
		};
	}
}