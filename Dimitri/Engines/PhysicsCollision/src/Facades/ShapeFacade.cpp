#include "ShapeFacade.h"
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d\b2_body.h>

using namespace PhysicsCollision;

Facades::ShapeFacade::ShapeFacade()
{
	_body = nullptr;
}

void Facades::ShapeFacade::add_body(b2Body* body) {
	_body = body;
}

void Facades::ShapeFacade::move_x(const float direction, const float value)const
{
	b2Vec2 vel = _body->GetLinearVelocity();
	float velChange;
	if (direction == -1) {
		velChange = (-30 * value) - vel.x;
	}
	else {
		velChange = (30 * value) - vel.x;
	}
	float impulse = _body->GetMass() * velChange; //disregard time factor
	_body->ApplyLinearImpulse(b2Vec2(impulse, 0), _body->GetWorldCenter(), true);
}

void Facades::ShapeFacade::move_y()const
{
	b2Vec2 vel = _body->GetLinearVelocity();
	float velChange;
	velChange = 50 - vel.y;
	float impulse = _body->GetMass() * velChange; //disregard time factor
	_body->ApplyLinearImpulse(b2Vec2(0, impulse), _body->GetWorldCenter(), true);
}

float Facades::ShapeFacade::get_angle()const
{
	return  _body->GetAngle() * RADIAN_IN_DEGREES;
}

b2Body* Facades::ShapeFacade::get_body()const
{
	return _body;
}