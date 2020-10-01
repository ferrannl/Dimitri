#pragma once

#include "ShapeAdapter.h"

class Shape {
public:
	int x;
	int y;
	ShapeAdapter* shapeAdapter;
	Shape();
	Shape(std::vector<std::pair<float, float>> position);
};