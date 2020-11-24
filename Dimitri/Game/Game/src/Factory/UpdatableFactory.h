#pragma once
#include "../Models/Abstract/Updatable.h"
#include "../interfaces/IFactory.h"

namespace Game {
	namespace Factories {
		class UpdatableFactory : public Interfaces::IFactory<Models::Updatable> {
		private:
			std::vector<int> _lights;
		public:
			UpdatableFactory();

			std::shared_ptr<Models::Updatable> create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::DirectionEnum state);
		};
	}
}