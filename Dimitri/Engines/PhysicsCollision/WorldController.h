#pragma once

#include "World.h"
#include "ShapeController.h"
#include <string>
#define DllExport   __declspec( dllexport )


class __declspec(dllexport) WorldController
{
private:
	World _world;
	ShapeController _shapeController;
public:
	WorldController();
	void setup_world(float width, float height);
	void clean_up();
	Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic);
	void simulate();
};