#include "WorldAdapter.h"
#include <iostream>

WorldAdapter::WorldAdapter()
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = new b2World(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -1.0f);
	_groundBody = _world->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(1.0f, 1.0f);
	_groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	_body = _world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_body->CreateFixture(&fixtureDef);
}

void WorldAdapter::add_shape(Shape shape)
{
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape.shapeAdapter.get_shape();
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_body->CreateFixture(&fixtureDef);
}

void WorldAdapter::simulate()
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	for (int32 i = 0; i < 60; ++i)
	{
		_world->Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = _body->GetPosition();
		float angle = _body->GetAngle();
		std::cout << i;
		printf(" %4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}
}
