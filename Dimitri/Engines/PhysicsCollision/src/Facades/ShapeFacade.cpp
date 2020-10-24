#include "ShapeFacade.h"

PhysicsCollision::Facades::ShapeFacade::ShapeFacade()
{
	_shape = nullptr;
}

void PhysicsCollision::Facades::ShapeFacade::set_shape(std::shared_ptr<b2PolygonShape> shape)
{
	_shape = shape;
}

std::shared_ptr<b2PolygonShape> PhysicsCollision::Facades::ShapeFacade::get_shape() const
{
	return _shape;
}

void PhysicsCollision::Facades::ShapeFacade::add_body(b2Body* body) {
	_body = body;
}

float PhysicsCollision::Facades::ShapeFacade::get_x()const
{
	return _body->GetPosition().x;
}

b2Body* PhysicsCollision::Facades::ShapeFacade::get_body()
{
	return _body;
}

float PhysicsCollision::Facades::ShapeFacade::get_y()const
{
	return  _body->GetPosition().y;
}

void PhysicsCollision::Facades::ShapeFacade::move_x(const int value)const
{
	b2Vec2 vel = _body->GetLinearVelocity();
	float velChange;
	if (value == -1) {
		velChange = -30 - vel.x;
	}
	else {
		velChange = 30 - vel.x;
	}
	float impulse = _body->GetMass() * velChange; //disregard time factor
	_body->ApplyLinearImpulse(b2Vec2(impulse, 0), _body->GetWorldCenter(), true);
}

void PhysicsCollision::Facades::ShapeFacade::move_y()const
{
	b2Vec2 vel = _body->GetLinearVelocity();
	float velChange;
	velChange = 50 - vel.y;
	float impulse = _body->GetMass() * velChange; //disregard time factor
	_body->ApplyLinearImpulse(b2Vec2(0, impulse), _body->GetWorldCenter(), true);
}

float PhysicsCollision::Facades::ShapeFacade::get_angle()const
{
	return  _body->GetAngle() * RADIAN_IN_DEGREES;
}


