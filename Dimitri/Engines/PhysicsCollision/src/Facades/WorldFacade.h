#pragma once
#include <box2d/b2_world.h>
#include <vector>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "../Models/Shape.h"
#include <iostream>
#include <sstream>
#include <map>

namespace PhysicsCollision {
	namespace Facades {
		class __declspec(dllexport) WorldFacade {
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
