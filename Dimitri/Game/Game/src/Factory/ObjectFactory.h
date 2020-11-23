#pragma once
#include "../Models/Abstract/Object.h"
#include "../interfaces/IFactory.h"

namespace Game {
	namespace Factories {
		class ObjectFactory : public Interfaces::IFactory<Models::Object> {
		public:
			std::shared_ptr<Models::Object> create(Enums::TypeEnum type, int x, int y, int z, int height, int width, Enums::StateEnum state);
		};
	}
}