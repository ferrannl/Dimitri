#pragma once

#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include "Shape.h"

class WorldAdapter {
private:
	b2World* _world;
	b2Body* _groundBody;
	b2Body* _body;
public:
	WorldAdapter();
	void add_shape(Shape shape);
	void simulate();
};