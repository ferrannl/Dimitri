#include "WorldAdapter.h"

WorldAdapter::WorldAdapter()
{
	b2Vec2 gravity(0.0f, -10.0f);	
	_world = new b2World(gravity);
	b2BodyDef bodyDef;
	bodyDef.position.Set(0.0f, -10.0f);
	_body = _world->CreateBody(&bodyDef);
}
