#include "ShapeAdapter.h"

Adapters::ShapeAdapter::ShapeAdapter()
{
	_shape = nullptr;
}

Adapters::ShapeAdapter::ShapeAdapter(std::string type, std::vector<std::pair<float, float>> positions)
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

void Adapters::ShapeAdapter::add_body(b2Body* body)
{
	_body = body;
}

b2Shape& Adapters::ShapeAdapter::get_shape() const
{
	return *_shape;
}

float Adapters::ShapeAdapter::get_x()
{
	return _body->GetPosition().x;
}

float Adapters::ShapeAdapter::get_y()
{
	return _body->GetPosition().y;
}


