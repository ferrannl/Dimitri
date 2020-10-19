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
	bodyDef.position.Set(shape->get_x(), shape->get_y());
	_polygon = std::make_shared<b2PolygonShape>();
	if (shape->is_dynamic)
	{
		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.0f;
		bodyDef.type = b2_dynamicBody;
		float halfH = shape->get_height() / 2;

		float halfW = shape->get_width() / 2;

		float posY = shape->get_y() - shape->get_height() / 2;

		float posX = shape->get_x() + shape->get_width() / 2;

		_polygon->SetAsBox(halfW, halfH, b2Vec2(posX, posY), shape->get_angle());
		fixtureDef.shape = _polygon.get();
		body = _world->CreateBody(&bodyDef);
		body->CreateFixture(&fixtureDef);
		shape->get_shape_facade()->add_body(body);
		//std::shared_ptr<Models::Shape> _shape = std::make_shared<Models::Shape>(polygonShape.get());
	}
	else {
		std::shared_ptr<b2Shape> groundBox = shape->get_shape_facade()->get_shape();
		body = _world->CreateBody(&bodyDef);
		body->CreateFixture(groundBox.get(), 0.0f);
	}
	_bodies.push_back(body);
	_world_bodies[shape] = body;
	shape->get_shape_facade()->add_body(body);
}

b2PolygonShape Facades::WorldFacade::create_shape(std::shared_ptr<Models::Shape> shape)
{
//	/*if (shape->get_type() == "polygon")
//	{*/
//		b2PolygonShape  polygonShape;
//		float halfH = shape->get_height() / 2;
//
//		float halfW = shape->get_width() / 2;
//
//		float posY = shape->get_y() - shape->get_height() / 2;
//
//		float posX = shape->get_x() + shape->get_width() / 2;
//
//		polygonShape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), shape->get_angle());
//		return polygonShape;
//	/*}
//	else {
		b2PolygonShape polygonShape;
		return polygonShape;
//	}*/
}

std::map<std::shared_ptr<Models::Shape>, b2Body*> Facades::WorldFacade::get_world_bodies()
{
	return _world_bodies;
}


void Facades::WorldFacade::simulate() const	
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : _world_bodies)
	{
		//std::shared_ptr<Models::Shape> shape = std::make_shared<Models::Shape>(_polygon);
		b2Body* body = it.second;
		std::shared_ptr<Models::Shape> shape = it.first;

		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		shape->set_x(body->GetPosition().x - shape->get_width() / 2);
		shape->set_y(body->GetPosition().y + shape->get_height() / 2);
		printf("%4.2f %4.2f %4.2f \n", shape->get_x(), shape->get_y(), angle);
	}
}
