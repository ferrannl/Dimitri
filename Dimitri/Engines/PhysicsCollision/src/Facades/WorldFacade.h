#pragma once
#include <vector>
#include "../Models/Shape.h"
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <map>
#include <math.h> 

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
	* \namespace PhysicsCollision::Facades
	* \brief Namespace for the facades in the physics collision engine
	*/
	namespace Facades {
		/**
		* \class WorldFacade
		* \brief Class contains methods to interact with a b2World
		*/
		class PHYSICSCOLLISION_API WorldFacade {
		private:
			/**
			* \brief An instance of the b2World
			*/
			std::shared_ptr<b2World> _world;

			/**
			* \brief A list of Shaped linked to bodies, which are in this World
			*/
			std::map<std::shared_ptr<Models::Shape>, b2Body*> _world_bodies;

		public:
			WorldFacade();
			/**
			* \brief Destroy the body of a ShapeFacade
			*/
			void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);

			/**
			* \brief Simulates the World
			*/
			void simulate(float speed) const;

			/**
			* \brief Adds a Shape to the World
			*/
			void add_shape(std::shared_ptr<Models::Shape> shape);

			/**
			* \brief Creates a polygon body
			*/
			void create_polygon_body(b2PolygonShape& _shape, b2BodyDef& bodyDef, b2FixtureDef& fixtureDef, b2Body*& body, std::shared_ptr<Models::Shape> shape);
		};
	}
}
