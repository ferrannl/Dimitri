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
	public:
		World();
		World(const float width, const float height);
		void add_shape(std::shared_ptr<Shape> shape, const float x, const float y);
		void destroy_bodies();
		void simulate();
	};
}