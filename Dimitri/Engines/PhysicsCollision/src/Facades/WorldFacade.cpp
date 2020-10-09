#include "WorldFacade.h"
#include <iostream>

Facades::WorldFacade::WorldFacade() {}

Facades::WorldFacade::WorldFacade(float width, float height)
{
	b2Vec2 gravity(0.0f, -10.0f);   
	_world = std::make_shared<b2World>(gravity);
}

void Facades::WorldFacade::add_shape(std::shared_ptr<Models::Shape> shape, const float x, const float y)const
{
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    if (shape->is_dynamic)
    {
        fixtureDef.density = 1.0f;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
        b2Body* _body = _world->CreateBody(&bodyDef);
        fixtureDef.shape = shape->get_shape_facade()->get_shape().get();
        _body->CreateFixture(&fixtureDef);
        shape->get_shape_facade()->add_body(_body);
    }
    else {
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(x, y);
        b2Body* _groundBody = _world->CreateBody(&groundBodyDef);
        std::shared_ptr<b2Shape> groundBox= shape->get_shape_facade()->get_shape();
        _groundBody->CreateFixture(groundBox.get(), 0.0f);
        shape->get_shape_facade()->add_body(_groundBody);
    }
}

void Facades::WorldFacade::simulate()const
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);
}
