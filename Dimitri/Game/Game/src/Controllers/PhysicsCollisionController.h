#pragma once
#include <memory>
#include <src\Controllers\WorldController.h>

namespace Game {
	namespace Controllers {
		class PhysicsCollisionController {
		private:
			std::unique_ptr<PhysicsCollision::Controllers::WorldController> _world_controller;
		public:
			PhysicsCollisionController();

			/**
			*	Calls world_controller->simulate
			*/
			void simulate();

			/**
			*	Calls world_controller->destroy_bodies
			*/
			void destroy_shapes();

			/**
			*	Creates shape
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> create_shape(float x, float y, float width, float height, bool is_dynamic);
		};
	}
}