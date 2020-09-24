#include "ShapeAdapter.h"

ShapeAdapter::ShapeAdapter()
{
	_shape = nullptr;
}

ShapeAdapter::ShapeAdapter(std::string type)
{
	if (type == "polygon") {
		_shape = new b2PolygonShape{};
		((b2PolygonShape*)_shape)->SetAsBox(1.0f, 1.0f);
	}
}

b2Shape& ShapeAdapter::get_shape() const
{
	return *_shape;
}
