#include "ShapeAdapter.h"

ShapeAdapter::ShapeAdapter()
{
	_shape = nullptr;
}

ShapeAdapter::ShapeAdapter(std::string type)
{
	if (type == "polygon") {
		_shape = &b2PolygonShape{};
		
	}
}
