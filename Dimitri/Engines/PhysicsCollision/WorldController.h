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
	void setup_world();
	void clean_up();
	void create_shape(std::string type);
};