#pragma once
#include "../Models/IInteractable.h"
#include "../Enums/TypeEnum.cpp"

namespace Game {
	namespace Factories {
		class InteractableFactory {
		public:
			std::shared_ptr<Models::IInteractable> create(Game::Enums::TypeEnum type, int x, int y, int z, int height, int width);
		};
	}
}
