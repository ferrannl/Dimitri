#pragma once

#include <string>
#include "Shape.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Square.h"
#include <vector>

class ShapeFactory {
public:
	Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position);
};