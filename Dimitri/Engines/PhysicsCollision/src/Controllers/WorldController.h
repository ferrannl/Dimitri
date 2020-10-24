#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
#include <string>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Controllers {
	class PHYSICSCOLLISION_API WorldController {
	private:
		Models::World _world;
		ShapeController _shapeController;
	public:
		WorldController();
		void setup_world(const float width, const float height);
		Models::Shape create_shape(const std::string type, const float x, const float y, const std::vector<std::pair<float, float>> positions, const bool is_dynamic);
		void destroy_bodies();
		void simulate();
	};
}