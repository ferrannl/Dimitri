#include "ShapeAdapter.h"

ShapeAdapter::ShapeAdapter()
{
	_shape = nullptr;
}

ShapeAdapter::ShapeAdapter(std::string type, float width, float height)
{
	if (type == "polygon") {
		_shape = new b2PolygonShape{};
		((b2PolygonShape*)_shape)->SetAsBox(width, height);
	}
}

b2Shape& ShapeAdapter::get_shape() const
{
	return *_shape;
}
