#pragma once

#include "WorldController.h"
#include "ShapeController.h"

int main() {
	WorldController worldController = WorldController{};
	worldController.create_shape("polygon");
	worldController.simulate();

	return 0;
}