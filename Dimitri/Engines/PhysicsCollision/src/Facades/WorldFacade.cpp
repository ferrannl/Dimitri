#include "WorldFacade.h"

Facades::WorldFacade::WorldFacade()
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = std::make_shared<b2World>(gravity);
	_world_bodies = std::map<std::shared_ptr<Models::Shape>, b2Body*>();
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
	if (shape->is_dynamic)
	{
		b2FixtureDef fixtureDef;
		fixtureDef.density = 1.0f;
		bodyDef.type = b2_dynamicBody;
		std::shared_ptr<b2PolygonShape> polygonShape = std::make_shared<b2PolygonShape>();
		float halfH = shape->get_height() / 2;

		float halfW = shape->get_width() / 2;

		float posY = shape->get_y() - shape->get_height() / 2;

		float posX = shape->get_x() + shape->get_width() / 2;

		polygonShape->SetAsBox(halfW, halfH, b2Vec2(posX, posY), shape->get_angle());
		fixtureDef.shape = polygonShape.get();
		body = _world->CreateBody(&bodyDef);
		body->CreateFixture(&fixtureDef);
		_world_bodies[shape] = body;
	}
	else {
		std::shared_ptr<b2Shape> groundBox = shape->get_shape_facade()->get_shape();
		body = _world->CreateBody(&bodyDef);
		body->CreateFixture(groundBox.get(), 0.0f);
	}
	_bodies.push_back(body);
	shape->get_shape_facade()->add_body(body);
}

b2PolygonShape Facades::WorldFacade::create_shape(std::shared_ptr<Models::Shape> shape)
{
	/*if (shape->get_type() == "polygon")
	{*/
		b2PolygonShape  polygonShape;
		float halfH = shape->get_height() / 2;

		float halfW = shape->get_width() / 2;

		float posY = shape->get_y() - shape->get_height() / 2;

		float posX = shape->get_x() + shape->get_width() / 2;

		polygonShape.SetAsBox(halfW, halfH, b2Vec2(posX, posY), shape->get_angle());
		return polygonShape;
	/*}
	else {
		b2PolygonShape polygonShape;
		return polygonShape;
	}*/
}

void Facades::WorldFacade::simulate() const	
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	_world->Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : _world_bodies)
	{
		b2Body* body = it.second;
		std::shared_ptr<Models::Shape> shape = it.first;

		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		/*shape->set_x(body->GetWorldCenter().x - shape->get_width() / 2);
		shape->set_y(body->GetWorldCenter().y + shape->get_height() / 2);*/
		printf("%4.2f %4.2f %4.2f \n", position.x, position.y, angle);
	}

}
