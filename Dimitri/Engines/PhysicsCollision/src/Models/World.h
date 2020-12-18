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
		* \class World
		* \brief Class contains methods to use the shapes in the world
		*/
		class PHYSICSCOLLISION_API World {
		private:
			/**
			*\ brief An instance of WorldFacade
			*/
			std::shared_ptr<Facades::WorldFacade> _world_facade;

			/**
			* \brief A list of Shapes
			*/
			std::vector<std::shared_ptr<Models::Shape>> _shapes;
		public:
			World();
			World(float width, float height);

			/**
			* \brief Adds a Shape to the World in _shapes
			*/
			void add_shape(const std::shared_ptr<Models::Shape>& shape);

			/**
			* \brief Returns _shapes
			*/
			const std::vector<std::shared_ptr<Models::Shape>>& get_shapes() const;

			/**
			* \brief Destroys the bodies from all Shapes in _shapes
			*/
			void destroy_bodies()const;

			/**
			* \brief Destroys the body from a Shape in _shapes
			*/
			void destroy_body(const std::shared_ptr<Models::Shape>& shape);

			/**
			* \brief Simulates the World
			*/
			void simulate(float speed)const;
		};
	}
}
