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

namespace Facades {
	class __declspec(dllexport) WorldFacade {
	private:
		std::shared_ptr<b2World> _world;
		std::vector<b2Body*> _bodies;;
		std::map<std::shared_ptr<Models::Shape>, b2Body*> _world_bodies;
		b2Body* _body;
		std::shared_ptr<b2PolygonShape> _polygon;
	public:
		WorldFacade();
		void destroy_bodies();
		void simulate()const ;
		void add_shape(std::shared_ptr<Models::Shape>);
		b2PolygonShape create_shape(std::shared_ptr<Models::Shape> shape);
		std::map<std::shared_ptr<Models::Shape>, b2Body*> get_world_bodies();
	};
}