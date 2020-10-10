#pragma once
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "../Models/Shape.h"

namespace Facades {
	class __declspec(dllexport) WorldFacade {
	private:
		std::shared_ptr<b2World> _world;
		b2Body* _body;
		b2Body* _groundBody;
	public:
		WorldFacade();
		void destroy();
		void simulate()const ;
		void add_shape(std::shared_ptr<Models::Shape>, const float x, const float y);
	};
}