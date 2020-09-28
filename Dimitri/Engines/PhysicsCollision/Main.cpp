#pragma once

#include "WorldController.h"
#include "ShapeController.h"

int main() {
	WorldController worldController = WorldController{};
	worldController.setup_world(10.0f, 10.0f);
	worldController.create_shape("polygon", 1.0f, 4.0f, 1.0f, 1.0f);
	worldController.simulate();

	return 0;
}