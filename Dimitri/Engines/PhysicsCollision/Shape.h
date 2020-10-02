#pragma once

#include "ShapeAdapter.h"

class __declspec(dllexport) Shape{
public:
	int x;
	bool is_dynamic;
	int y;
	ShapeAdapter* shapeAdapter;
	Shape();
	Shape(std::vector<std::pair<float, float>> position);
	void add_body(b2Body* body);
	float get_x();
	float get_y();
};