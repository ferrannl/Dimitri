#include "WorldFacade.h"

Facades::WorldFacade::WorldFacade()
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = std::make_shared<b2World>(gravity);
	_bodies = {};
}

void Facades::WorldFacade::destroy_bodies()
{
	for (b2Body* _groundBody : _bodies)
	{
		_world->DestroyBody(_groundBody);
	}
}

void Facades::WorldFacade::add_shape(std::shared_ptr<Models::Shape> shape, const float x, const float y)
{
	b2Body* body;
	b2BodyDef bodyDef;
	if (shape->is_dynamic)
	{
		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.0f;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(x, y);
		body = _world->CreateBody(&bodyDef);
		fixtureDef.shape = shape->get_shape_facade()->get_shape().get();
		body->CreateFixture(&fixtureDef);
	}
	else {
		bodyDef.position.Set(x, y);
		body = _world->CreateBody(&bodyDef);
		std::shared_ptr<b2Shape> groundBox = shape->get_shape_facade()->get_shape();
		body->CreateFixture(groundBox.get(), 0.0f);
	}
	_bodies.push_back(body);
	shape->get_shape_facade()->add_body(body);
}

void Facades::WorldFacade::simulate() const
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);
}
