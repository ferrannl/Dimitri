#pragma once

#include "ShapeAdapter.h"

class Shape {
public:
	ShapeAdapter* shapeAdapter;
	Shape();
	Shape(float x, float y);
};