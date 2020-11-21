#pragma once
#include <memory>
#include <src\Controllers\WorldController.h>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		* \class PhysicsCollisionController
		* \brief Class contains the methods to interact with physics collision engine
		*/
		class PhysicsCollisionController {
		private:
			/**
			* \brief An instance of the WorldController
			*/
			std::unique_ptr<PhysicsCollision::Controllers::WorldController> _world_controller;
		public:
			PhysicsCollisionController();

			/**
			* \brief Simulates the World in the WorldController
			*/
			void simulate();

			/**
			* \brief Destroys the bodies in the World
			*/
			void destroy_shapes();

			/**
			* \brief Loads the Shape into the World
			*/
			void load_shape(const std::shared_ptr<PhysicsCollision::Models::Shape>& _shape);

			/**
			* \brief Setup world
			*/
			void setup_world(int height, int width);

		};
	}
}
