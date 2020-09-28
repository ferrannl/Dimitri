#pragma once

#include <string>
#include "Shape.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Square.h"

class ShapeFactory {
public:
	Shape create_shape(std::string type, float x, float y);
};