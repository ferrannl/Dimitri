#pragma once

#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>

class ShapeAdapter {
private:
	b2Shape* _shape;
public:
	ShapeAdapter();
	ShapeAdapter(std::string type);
	b2Shape& get_shape() const;
};