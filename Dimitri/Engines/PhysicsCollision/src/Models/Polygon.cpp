#include "Polygon.h"

Models::Polygon::Polygon()
{
	_shape_facade = nullptr;
}

Models::Polygon::Polygon(const std::vector<std::pair<float, float>> positions, bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	_shape_facade = std::make_shared<Facades::ShapeFacade>( "polygon", positions );
}