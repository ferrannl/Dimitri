#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
#include <string>

namespace Controllers {
	class __declspec(dllexport) WorldController {
	private:
		Models::World _world;
		ShapeController _shapeController;
	public:
		WorldController();
		void setup_world(float width, float height);
		void clean_up();
		Models::Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic);
		void simulate();
	};
}