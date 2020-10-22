#include "ShapeFacade.h"

Facades::ShapeFacade::ShapeFacade()
{
	_shape = nullptr;
}

Facades::ShapeFacade::ShapeFacade(const std::string type, float width, float height)
{
	//int size = positions.size();
	/*b2Vec2* vertices = new b2Vec2[size];
	int counter = 0;
	for (std::vector<std::pair<float, float>>::iterator it = positions.begin(); it != positions.end(); ++it)
	{
		vertices[counter].Set(it->first, it->second);
		counter++;
	}*/
	//if (type == "polygon") {
	//	_shape = std::make_shared<b2PolygonShape>();
	//	
	//	//_shape->Set(vertices, size);
	//}
}

void Facades::ShapeFacade::set_shape(std::shared_ptr<b2PolygonShape> shape)
{
	_shape = shape;
}

std::shared_ptr<b2PolygonShape> Facades::ShapeFacade::get_shape() const
{
	return _shape;
}

void Facades::ShapeFacade::add_body(b2Body* body) {
	_body = body;
}

float Facades::ShapeFacade::get_x()const
{
	return _body->GetPosition().x;
}

b2Body* Facades::ShapeFacade::get_body()
{
	return _body;
}

float Facades::ShapeFacade::get_y()const
{
	return  _body->GetPosition().y;
}

void Facades::ShapeFacade::move_x(const int value)const
{
	b2Vec2 vel = _body->GetLinearVelocity();
	float velChange;
	if (value == -1) {
		velChange = -30 - vel.x;
		/*vel.x = vel.x - 30.0f;
		vel.y = 0;*/
	}
	else {
		velChange = 30 - vel.x;
		/*vel.x = vel.x + 30.0f;
		vel.y = 0;*/
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


