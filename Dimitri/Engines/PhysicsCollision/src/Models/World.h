#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

namespace PhysicsCollision {
	namespace Models {
		class __declspec(dllexport) World {
		private:
			PhysicsCollision::Facades::WorldFacade _world_facade;
		public:
			World();
			World(const float width, const float height);
			void add_shape(std::shared_ptr<Shape> shape);
			std::vector<std::shared_ptr<Models::Shape>> get_shapes();
			void destroy_bodies();
			void simulate();
		};
	}
}