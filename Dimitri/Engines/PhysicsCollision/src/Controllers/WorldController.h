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
		void create_shape(const std::string type, const float x, const float y, const std::vector<std::pair<float, float>> positions, const bool is_dynamic);
		void destroy_bodies();
		void simulate();
		std::shared_ptr<std::vector<std::unique_ptr<Models::Shape>>> get_shapes()const;
	};
}