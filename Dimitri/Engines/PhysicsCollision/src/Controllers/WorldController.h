#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
#include <string>

namespace PhysicsCollision {
	namespace Controllers {
		class __declspec(dllexport) WorldController {
		private:
			Models::World _world;
			ShapeController _shapeController;
		public:
			WorldController();
			void setup_world(const float width, const float height);
			Models::Shape create_shape(const std::string type, const float x, const float y, float width, float height, const bool is_dynamic);
			void destroy_bodies();
			void simulate();
			std::map<std::shared_ptr<Models::Shape>, b2Body*> get_world_bodies();
		};
	}
}