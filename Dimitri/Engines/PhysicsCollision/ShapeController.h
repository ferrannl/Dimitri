#pragma once

#include <vector>
#include "Shape.h"
#include "ShapeFactory.h"

class ShapeController {
private:
	ShapeFactory* _shapeFactory;
public:
	ShapeController();
	Shape create_shape(std::string type, float x, float y, float width, float height);
	bool has_collision(Shape shape1, Shape shape2);
};