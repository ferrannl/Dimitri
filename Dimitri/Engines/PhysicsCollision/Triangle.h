#pragma once

class Triangle : public Shape {
public:
	Triangle();
	Triangle(float x, float y, std::vector<std::pair<float, float>> position);
};