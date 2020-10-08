#include "Polygon.h"

Models::Polygon::Polygon()
{
	_shape_facade = nullptr;
}

Models::Polygon::Polygon(std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	_shape_facade = new Facades::ShapeFacade{ "polygon" , positions };
}