#include "WorldFacade.h"
using namespace PhysicsCollision;

Facades::WorldFacade::WorldFacade()
{
	b2Vec2 gravity(0.0f, -10.0f);
	_world = std::make_shared<b2World>(gravity);
	_world_bodies = std::map<std::shared_ptr<Models::Shape>, b2Body*>();
}

void Facades::WorldFacade::destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade)
{
	_world->DestroyBody(shape_facade->get_body());
}

void Facades::WorldFacade::add_shape(std::shared_ptr<Models::Shape> shape)
{
	b2FixtureDef fixtureDef;
	b2Body* body = nullptr;
	b2BodyDef bodyDef;
	if (shape->get_type() == Enums::ShapeEnum::Polygon) {
		b2PolygonShape _shape;
		bodyDef.position.Set(shape->get_x() + shape->get_width() / 2, shape->get_y() + shape->get_height() / 2);
		bodyDef.type = b2_dynamicBody;
		bodyDef.angle = 0;
		body = _world->CreateBody(&bodyDef);
		const int32 count = 3;
		b2Vec2 vertices[count];

		vertices[0].Set(0, 0);
		vertices[1].Set(10, 0);
		vertices[2].Set(5, 5);

		_shape.Set(vertices, count);
		fixtureDef.shape = &_shape;
		body->CreateFixture(&fixtureDef);
		//x + width / 2 naar x + width, y + height
		//x + width, y + height naar x, y+ height
		//x, y+ height naar x + width / 2
		//Polygon tekenen dmv vertices
	}
	else if (shape->get_type() == Enums::ShapeEnum::Square) {
		b2PolygonShape _shape;
		_shape.SetAsBox(shape->get_width() / 2, shape->get_height() / 2);
		bodyDef.position.Set(shape->get_x() + shape->get_width() / 2, shape->get_y() + shape->get_height() / 2);
		create_polygon_body(_shape, bodyDef, fixtureDef, body, shape);
	}
	_world_bodies[shape] = body;
	shape->get_shape_facade()->add_body(body);
}

void Facades::WorldFacade::create_polygon_body(b2PolygonShape &_shape, b2BodyDef &bodyDef, b2FixtureDef &fixtureDef, b2Body* &body, std::shared_ptr<Models::Shape> shape) {
	if (shape->get_is_dynamic())
	{
		bodyDef.type = b2_dynamicBody;
		bodyDef.angle = 0;
		body = _world->CreateBody(&bodyDef);
		fixtureDef.shape = &_shape;
		if (shape->get_is_interactable())
		{
			fixtureDef.filter.groupIndex = 1;
			fixtureDef.filter.categoryBits = 0x0001;
		}
		else {
			fixtureDef.filter.groupIndex = -1;
			fixtureDef.filter.categoryBits = 0x0002;
		}
		fixtureDef.filter.maskBits = 1;
		fixtureDef.friction = 1.0f;
		fixtureDef.density = 1.0f;
		body->CreateFixture(&fixtureDef);
	}
	else {
		body = _world->CreateBody(&bodyDef);
		body->SetType(b2_staticBody);
		body->CreateFixture(&_shape, 0.0f);
	}
}

void Facades::WorldFacade::simulate() const
{
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 6;
	_world->Step(timeStep, velocityIterations, positionIterations);

	for (auto const& it : _world_bodies)
	{
		std::shared_ptr<Models::Shape> shape = it.first;
		b2Body* body = it.second;

		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		shape->set_x(body->GetWorldCenter().x - shape->get_width() / 2);
		shape->set_y(body->GetWorldCenter().y - shape->get_height() / 2);
	}
}
