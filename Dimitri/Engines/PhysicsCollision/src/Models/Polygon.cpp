#include "Polygon.h"

Models::Polygon::Polygon()
{
	shapeAdapter = nullptr;
}

Models::Polygon::Polygon(float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	this->x = x;
	this->y = y;
	this->is_dynamic = is_dynamic;
	shapeAdapter = new Adapters::ShapeAdapter{ "polygon" , positions };
}

void Models::Polygon::add_body(b2Body* body)
{
	shapeAdapter->add_body(body);
}
