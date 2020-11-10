#pragma once
#include <memory>
#include <src\Controllers\WorldController.h>

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains all code to interact with physics collision engine to simulate gravity and collision
		*/
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