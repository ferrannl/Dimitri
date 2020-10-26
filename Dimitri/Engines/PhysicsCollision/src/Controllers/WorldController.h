#pragma once
#include "../Models/World.h"
#include "ShapeController.h"
#include <string>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else 
#define PHYSICSCOLLISION_API __declspec(dllimport)
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
		void create_shape(const std::string type, const float x, const float y, const std::vector<std::pair<float, float>> positions, const bool is_dynamic);
		void destroy_bodies();
		void simulate();
		std::shared_ptr<std::vector<std::unique_ptr<Models::Shape>>> get_shapes()const;
	};
}