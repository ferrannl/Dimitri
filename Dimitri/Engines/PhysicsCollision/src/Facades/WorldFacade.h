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
			std::vector<b2Body*> _bodies;;
			std::map<std::shared_ptr<PhysicsCollision::Models::Shape>, b2Body*> _world_bodies;
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _shapes;
			b2Body* _body;
			std::shared_ptr<b2PolygonShape> _polygon;
		public:
			WorldFacade();
			void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);
			void simulate()const;
			void add_shape(std::unique_ptr<PhysicsCollision::Models::Shape> &shape, const float x, const float y);
			b2PolygonShape create_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape);
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> get_shapes();
		};
	}
}
