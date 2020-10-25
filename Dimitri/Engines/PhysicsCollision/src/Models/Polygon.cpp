#include "Polygon.h"
using namespace PhysicsCollision;

Models::Polygon::Polygon()
{
	_type == "polygon";
}

Models::Polygon::Polygon( bool is_dynamic)
{
	this->is_dynamic = is_dynamic;
	_type == "polygon";
}