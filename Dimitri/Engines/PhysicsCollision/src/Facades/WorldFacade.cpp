#include "WorldFacade.h"

Facades::WorldFacade::WorldFacade()
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = std::make_shared<b2World>(gravity);
	_world_bodies = std::map<std::shared_ptr<Models::Shape>, b2Body*>();
	_body = {};
	_polygon = {};
	_bodies = {};
}

void Facades::WorldFacade::destroy_bodies()
{
	for (b2Body* _groundBody : _bodies)
	{
		_world->DestroyBody(_groundBody);
	}
}

void Facades::WorldFacade::add_shape(std::shared_ptr<Models::Shape> shape)
{
	b2Body* body;
	b2BodyDef bodyDef;
	bodyDef.position.Set(shape->get_x(),shape->get_y());
	_polygon = std::make_shared<b2PolygonShape>();
	if (shape->get_is_dynamic())
	{
		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.0f;
		bodyDef.type = b2_dynamicBody;
		b2PolygonShape _shape = create_shape(shape);
		fixtureDef.shape = &_shape;
		body = _world->CreateBody(&bodyDef);
		body->CreateFixture(&fixtureDef);
	}else {
		b2PolygonShape _shape = create_shape(shape);
		bodyDef.type = b2_staticBody;
		body = _world->CreateBody(&bodyDef);
		body->SetType(b2_staticBody);
		body->CreateFixture(&_shape, 0.0f);
	}
	_bodies.push_back(body);
	_world_bodies[shape] = body;
	shape->get_shape_facade()->add_body(body);
}

b2PolygonShape Facades::WorldFacade::create_shape(std::shared_ptr<Models::Shape> shape)
{
	if (shape->get_type() == "polygon")
	{
		b2PolygonShape  polygonShape;
		float halfH = shape->get_height() / 2;

		float halfW = shape->get_width() / 2;

		float posY = shape->get_y() - shape->get_height() / 2;

		float posX = shape->get_x() + shape->get_width() / 2;

		polygonShape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), shape->get_angle());
		return polygonShape;
	}
	else {
		b2PolygonShape polygonShape;
		return polygonShape;
	}
}

std::map<std::shared_ptr<Models::Shape>, b2Body*> Facades::WorldFacade::get_world_bodies()
{
	return _world_bodies;
}


void Facades::WorldFacade::simulate() const	
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 6;
	_world->Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : _world_bodies)
	{
		//std::shared_ptr<Models::Shape> shape = std::make_shared<Models::Shape>(_polygon);
		std::shared_ptr<Models::Shape> shape = it.first;
		b2Body* body = it.second;

		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		shape->set_x(body->GetWorldCenter().x - shape->get_width() / 2);
		shape->set_y(body->GetWorldCenter().y + shape->get_height() / 2);			
	}
}
