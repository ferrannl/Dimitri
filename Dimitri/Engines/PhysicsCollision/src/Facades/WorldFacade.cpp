#include "WorldFacade.h"
#include <iostream>

Facades::WorldFacade::WorldFacade() {}

Facades::WorldFacade::WorldFacade(float width, float height)
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = new b2World(gravity);

	create_ground_body(0.0f, height, width, 1.0f); // top	
	create_ground_body(0.0f, -1.0f, width, 1.0f); // bottom	
	create_ground_body(-1.0f, 0.0f, 1.0f, height); // left
	create_ground_body(width, 0.0f, 1.0f, height); // right
}

void Facades::WorldFacade::create_ground_body(float x, float y, float width, float height)
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(x, y);
	b2Body* _groundBody = _world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(width, height);
	_groundBody->CreateFixture(&groundBox, 0.0f);
}

void Facades::WorldFacade::add_shape(Models::Shape* shape, float x, float y)
{
	b2BodyDef bodyDef;
	if (shape->is_dynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	bodyDef.position.Set(x, y);
	b2Body* _body = _world->CreateBody(&bodyDef);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = shape->get_shape_facade()->get_shape();
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_body->CreateFixture(&fixtureDef);
	shape->get_shape_facade()->add_body(_body);
}

void Facades::WorldFacade::simulate()
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);
}