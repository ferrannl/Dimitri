#pragma once
#include <box2d/b2_world.h>
#include <vector>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "../Models/Shape.h"

namespace Facades {
	class __declspec(dllexport) WorldFacade {
	private:
		std::shared_ptr<b2World> _world;
		std::vector<b2Body*> _bodies;
	public:
		WorldFacade();
		void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);
		void simulate()const ;
		void add_shape(std::unique_ptr<Models::Shape> &shape, const float x, const float y);
	};
}