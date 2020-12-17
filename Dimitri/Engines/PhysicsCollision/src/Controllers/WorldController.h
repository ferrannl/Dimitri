#pragma once
#include "../Models/World.h"
#include <string>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else
#define PHYSICSCOLLISION_API __declspec(dllimport)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

/**
* \namespace PhysicsCollision
* \brief Namespace for the physics collision engine
*/
namespace PhysicsCollision {
	/**
	* \namespace PhysicsCollision::Controllers
	* \brief Namespace for the controllers in the physics collision engine
	*/
	namespace Controllers {
		/**
		* \class WorldController
		* \brief Class contains methods to setup the world and interact with the shapes
		*/
		class PHYSICSCOLLISION_API WorldController {
		private:
			/**
			* \brief An instance of the World
			*/
			Models::World _world;
		public:
			WorldController();

			/**
			* \brief Sets up the world with a width and height
			*/
			void setup_world(float width, float height);

			/**
			* \brief Loads Shapes into the world
			*/
			void load_shape(const std::shared_ptr<PhysicsCollision::Models::Shape>& shape);

			/**
			* \brief Destroys the bodies of the Shapes in the World
			*/
			void destroy_bodies() const;

			/**
			* \brief Destroys a body in the World
			*/
			void destroy_body(const std::shared_ptr<PhysicsCollision::Models::Shape>& shape);

			/**
			* \brief Simulates the world
			*/
			void simulate(float speed)const;

			/**
			* \brief Returns all the Shapes in the World
			*/
			std::vector<std::shared_ptr<Models::Shape>> get_shapes()const;
		};
	}
}
