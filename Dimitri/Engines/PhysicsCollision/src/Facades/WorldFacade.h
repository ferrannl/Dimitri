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

namespace PhysicsCollision {
	namespace Facades {
		class PHYSICSCOLLISION_API WorldFacade {
		private:
			std::shared_ptr<b2World> _world;
			std::map<std::shared_ptr<Models::Shape>, b2Body*> _world_bodies;
		public:
			WorldFacade();
			void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);
			void simulate()const;
			void add_shape(std::shared_ptr<Models::Shape> shape);
			void create_polygon_body(b2PolygonShape &_shape, b2BodyDef &bodyDef, b2FixtureDef &fixtureDef, b2Body* &body, std::shared_ptr<Models::Shape> shape);
		};
	}
}
