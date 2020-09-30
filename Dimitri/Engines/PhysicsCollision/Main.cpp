#pragma once

#include "WorldController.h"
#include "ShapeController.h"
#include <map>

int main() {
	WorldController worldController = WorldController{};
	worldController.setup_world(10.0f, 10.0f);
	std::vector<std::pair<float, float>> position{ {0.0f,0.0f}, {1.0f,1.0f}, {0.0f, 1.0f} };
	worldController.create_shape("polygon",1.0f, 4.0f ,position);
	//worldController.create_shape("polygon", position);
	worldController.simulate();

	return 0;
}