#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon()
{
	shapeAdapter = nullptr;
}

Polygon::Polygon(float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic)
{
	this->x = x;
	this->y = y;
	this->is_dynamic = is_dynamic;
	shapeAdapter = new ShapeAdapter{ "polygon" , position};
}

void Polygon::add_body(b2Body* body)
{
	shapeAdapter->add_body(body);
}
