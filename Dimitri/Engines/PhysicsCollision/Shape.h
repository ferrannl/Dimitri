#pragma once

#include "ShapeAdapter.h"

class Shape {
public:
	int x;
	int y;
	ShapeAdapter* shapeAdapter;
	Shape();
	Shape(float x, float y, float width, float height);
};