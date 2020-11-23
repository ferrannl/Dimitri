#pragma once
#include "../Models/Abstract/Interactable.h"
#include "../interfaces/IFactory.h"

namespace Game {
	namespace Factories {
		class InteractableFactory : public Interfaces::IFactory<Models::Interactable> {
		private:
			std::vector<int> _lights;
		public:
			InteractableFactory();

			std::shared_ptr<Models::Interactable> create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::StateEnum state);
		};
	}
}