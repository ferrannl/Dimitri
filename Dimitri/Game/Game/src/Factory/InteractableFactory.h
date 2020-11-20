#pragma once
#include "IFactory.h"
#include "../Models/IInteractable.h"

namespace Game {
	namespace Factories {
		class InteractableFactory {
		public:
			InteractableFactory();

			std::shared_ptr<Models::IInteractable> create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width);
		};
	}
}
