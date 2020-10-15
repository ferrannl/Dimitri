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
		//std::vector<std::unique_ptr<b2Body>> _bodies;
	public:
		WorldFacade();
		void simulate()const ;
		void add_shape(std::shared_ptr<Models::Shape>, const float x, const float y);
		void destroy_body(b2Body* body);
	};
}