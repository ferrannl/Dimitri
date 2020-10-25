#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
#include <string>

namespace PhysicsCollision {
	namespace Controllers {
		class __declspec(dllexport) WorldController {
		private:
			PhysicsCollision::Models::World _world;
			PhysicsCollision::Controllers::ShapeController _shapeController;
		public:
			WorldController();
			void setup_world(const float width, const float height);
			void create_shape(const std::string type, const float x, const float y, float width, float height, const bool is_dynamic);
			void destroy_bodies();
			void simulate();
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> get_shapes()const;
		};
	}
}
