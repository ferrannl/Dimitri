#pragma once

#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "Shape.h"

class WorldAdapter {
private:
	b2World* _world;
public:
	WorldAdapter();
	WorldAdapter(float width, float height);
	void add_shape(Shape shape);
	void simulate();
	void create_ground_body(float x, float y, float width, float height);
};