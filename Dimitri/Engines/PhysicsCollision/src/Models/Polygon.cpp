#include "Polygon.h"

PhysicsCollision::Models::Polygon::Polygon()
{
	_type == "polygon";
}

PhysicsCollision::Models::Polygon::Polygon( bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	_type == "polygon";
}