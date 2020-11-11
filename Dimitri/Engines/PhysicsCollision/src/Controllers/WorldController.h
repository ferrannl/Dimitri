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
* Namespace for the PhysicsCollision engine
*/
namespace PhysicsCollision {
	/**
	* Namespace for the Controllers
	*/
	namespace Controllers {
		/**
		* Contains methods to setup the world and check colliding shapes. Also contains the simulate which updates the position of the shape of the Box2D body
		*/
		class PHYSICSCOLLISION_API WorldController {
		private:
			/**
			* World model that contains the shapes
			*/
			Models::World _world;
		public:
			WorldController();
			/**
			* Sets up the world with shapes
			*/
			void setup_world(const float width, const float height);
			/**
			*	Loads the created shapes into the world
			*/
			void load_shapes(std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes);
			/**
			* Destroys the bodies from Box2D
			*/
			void destroy_bodies();
			/**
			* Simulates the world and lets all shapes fall
			*/
			void simulate();
			/**
			* Gets all the shapes in the world
			*/
			std::vector<std::shared_ptr<Models::Shape>> get_shapes()const;
		};
	}
}
