#pragma once
#include "../Models/IObject.h"
#include "../interfaces/IFactory.h"

namespace Game {
	namespace Factories {
		class ObjectFactory : public Interfaces::IFactory<Models::IObject> {
		public:
			std::shared_ptr<Models::IObject> create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::StateEnum state);
		};
	}
}