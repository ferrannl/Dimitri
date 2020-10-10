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
		void setup_world(const float width, const float height);
		void clean_up()const;
		Models::Shape create_shape(const std::string type, const float x, const float y, const std::vector<std::pair<float, float>> positions, const bool is_dynamic);
		void destroy();
		void simulate();
	};
}