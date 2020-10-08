#pragma once
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "../Models/Shape.h"

namespace Facades {
	class __declspec(dllexport) WorldAdapter {
	private:
		b2World* _world;
	public:
		WorldAdapter();
		WorldAdapter(float width, float height);
		void add_shape(Models::Shape shape, float x, float y);
		void simulate();
		void create_ground_body(float x, float y, float width, float height);
	};
}