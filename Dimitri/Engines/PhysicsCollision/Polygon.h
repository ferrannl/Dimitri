#pragma once
#include <map>

class Polygon : public Shape {
public:
	Polygon();
	Polygon(float x, float y, std::vector<std::pair<float, float>> position);
};