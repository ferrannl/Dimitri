#pragma once

#include "World.h"
#include "ShapeController.h"
#include <string>

class WorldController {
private:
	World _world;
	ShapeController _shapeController;
public:
	WorldController();
	void setup_world(float width, float height);
	void clean_up();
	void create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position);
	void simulate();
};