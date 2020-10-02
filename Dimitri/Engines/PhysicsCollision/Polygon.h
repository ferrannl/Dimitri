#pragma once
#include <map>

class __declspec(dllexport) Polygon: public Shape {
public:
	Polygon();
	Polygon(float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic);
	void add_body(b2Body* body);
};