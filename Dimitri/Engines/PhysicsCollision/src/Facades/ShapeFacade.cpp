#include "ShapeFacade.h"

Facades::ShapeFacade::ShapeFacade()
{
	_shape = nullptr;
}

Facades::ShapeFacade::ShapeFacade(std::string type, std::vector<std::pair<float, float>> positions)
{
	int size = positions.size();
	b2Vec2* vertices = new b2Vec2[size];
	int counter = 0;
	for (std::vector<std::pair<float, float>>::iterator it = positions.begin(); it != positions.end(); ++it)
	{
		vertices[counter].Set(it->first, it->second);
		counter++;
	}
	if (type == "polygon") {
		_shape = new b2PolygonShape{};
		((b2PolygonShape*)_shape)->Set(vertices, size);
	}
}

b2Shape* Facades::ShapeFacade::get_shape() const
{
	return _shape;
}

void Facades::ShapeFacade::add_body(b2Body* body) {
	_body = body;
}

float Facades::ShapeFacade::get_x()
{
	return _body->GetPosition().x;
}

float Facades::ShapeFacade::get_y()
{
	return  _body->GetPosition().y;
}

float Facades::ShapeFacade::get_angle()
{
	return  _body->GetAngle() * RADIAN_IN_DEGREES;
}


