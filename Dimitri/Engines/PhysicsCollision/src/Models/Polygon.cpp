#include "Polygon.h"
using namespace PhysicsCollision;

Models::Polygon::Polygon()
{
	_type == Enums::ShapeEnum::Polygon;
}

Models::Polygon::Polygon( bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	_type == Enums::ShapeEnum::Polygon;
}