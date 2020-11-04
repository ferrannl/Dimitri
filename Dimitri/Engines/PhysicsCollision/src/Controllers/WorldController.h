#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
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
			/**
			* ShapeController that creates shapes
			*/
			ShapeController _shapeController;
		public:
			WorldController();
			/**
			* Sets up the world with shapes
			*/
			void setup_world(const float width, const float height);
			/**
			* Creates the shape based on given parameters
			*/
			std::shared_ptr<Models::Shape> create_shape(const Enums::ShapeEnum type, const float x, const float y, float width, float height, const bool is_dynamic);
			/**
			* Returns true when there is collision between two shapes. Else returns false
			*/
			bool check_collision(std::shared_ptr<Models::Shape> shape1, std::shared_ptr<Models::Shape> shape2);
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
