#include "Polygon.h"

Models::Polygon::Polygon()
{
	//_shape_facade = nullptr;
	type == "polygon";
}

Models::Polygon::Polygon( bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	type == "polygon";
}