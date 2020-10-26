#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else 
#define PHYSICSCOLLISION_API __declspec(dllimport)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Models {
	class PHYSICSCOLLISION_API World {
	private:
		Facades::WorldFacade _world_facade;
		std::shared_ptr<std::vector <std::unique_ptr<Shape>>> _shapes;
	public:
		World();
		World(const float width, const float height);
		void add_shape(Models::Shape shape, const float x, const float y);
		void destroy_bodies();
		void simulate();
		std::shared_ptr<std::vector <std::unique_ptr<Shape>>> get_shapes()const;
	};
}