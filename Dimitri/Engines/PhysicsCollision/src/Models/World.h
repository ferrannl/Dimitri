#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
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