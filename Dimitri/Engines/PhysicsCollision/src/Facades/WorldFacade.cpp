#include "WorldFacade.h"
#include <iostream>

Facades::WorldFacade::WorldFacade() {}

Facades::WorldFacade::WorldFacade(float width, float height)
{
	b2Vec2 gravity(0.0f, -10.0f);   
	_world = new b2World(gravity);
}

void Facades::WorldFacade::add_shape(Models::Shape* shape, float x, float y)
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    if (shape->is_dynamic)
    {
        fixtureDef.density = 1.0f;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
        b2Body* _body = _world->CreateBody(&bodyDef);
        fixtureDef.shape = shape->get_shape_facade()->get_shape();
        _body->CreateFixture(&fixtureDef);
        shape->get_shape_facade()->add_body(_body);
    }
    else {
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(x, y);
        b2Body* _groundBody = _world->CreateBody(&groundBodyDef);
        b2Shape* groundBox = shape->get_shape_facade()->get_shape();
        _groundBody->CreateFixture(groundBox, 0.0f);
        shape->get_shape_facade()->add_body(_groundBody);
    }
}

void Facades::WorldFacade::simulate()
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);
}
