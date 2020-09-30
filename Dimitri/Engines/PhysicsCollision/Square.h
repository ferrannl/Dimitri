#pragma once

#include "Shape.h"

class Square : public Shape {
public:
	Square();
	Square(float x, float y, std::vector<std::pair<float, float>> position);
};