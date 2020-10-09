#pragma once
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "../Models/Shape.h"

namespace Facades {
	class __declspec(dllexport) WorldFacade {
	private:
		b2World* _world;
	public:
		WorldFacade();
		WorldFacade(float width, float height);
		void simulate();
		void add_shape(Models::Shape* shape, float x, float y);
	};
}