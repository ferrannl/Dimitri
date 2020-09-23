#pragma once

#include <vector>
#include "Shape.h"

class ShapeController {
public:
	ShapeController();
	Shape create_shape(std::string type);
	bool has_collision(Shape shape1, Shape shape2);
};