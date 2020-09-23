#pragma once

#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>

class WorldAdapter {
private:
	b2World* _world;
	b2Body* _body;
public:
	WorldAdapter();
};