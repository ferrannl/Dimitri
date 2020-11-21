#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

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
	* \namespace PhysicsCollision::Models
	* \brief Namespace for the models in the physics collision engine
	*/
	namespace Models {
		/**
		* Contains all the methods for shape usage in World
		*/
		class PHYSICSCOLLISION_API World {
		private:
			/**
			* World Facade of the World
			*/
			Facades::WorldFacade _world_facade;
			/**
			* Shapes list of the world
			*/
			std::vector<std::shared_ptr<Models::Shape>> _shapes;
		public:
			World();
			/**
			* World Constructor for initializing variables
			*/
			World(const float width, const float height);
			/**
			* Method that adds the shape to a world
			*/
			void add_shape(const std::shared_ptr<Models::Shape>& shape);
			/**
			* Returns the shapes from a world
			*/
			std::vector<std::shared_ptr<Models::Shape>> get_shapes()const;
			/**
			* Destroys the body from this world
			*/
			void destroy_bodies();
			/**
			* Calls the simulate from the World Facade
			*/
			void simulate();
		};
	}
}
