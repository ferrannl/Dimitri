#pragma once
#include <vector>
#include "../Models/Shape.h"
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <map>

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
* Namespace for the PhysicsCollision
*/
namespace PhysicsCollision {
	/**
	* Namespace for the Facades
	*/
	namespace Facades {
		/**
		* Contains methods to add and destroy the bodies of the world
		*/
		class PHYSICSCOLLISION_API WorldFacade {
		private:
			/**
			* World object of the WorldFacade
			*/
			std::shared_ptr<b2World> _world;
			/**
			* World bodies KeyValuePair of Shape and b2Body 
			*/
			std::map<std::shared_ptr<Models::Shape>, b2Body*> _world_bodies;
		public:
			WorldFacade();
			/**
			* Destroy the body of the world
			*/
			void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);
			/**
			* Simulates the world object with gravity
			*/
			void simulate()const;
			/**
			* Adds the shape to the world shapes
			*/
			void add_shape(std::shared_ptr<Models::Shape> shape);
			/**
			* Creates a polygon object
			*/
			void create_polygon_body(b2PolygonShape &_shape, b2BodyDef &bodyDef, b2FixtureDef &fixtureDef, b2Body* &body, std::shared_ptr<Models::Shape> shape);
		};
	}
}
