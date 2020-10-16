#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

namespace Models {
	class __declspec(dllexport) World {
	private:
		Facades::WorldFacade _world_facade;
	public:
		World();
		World(const float width, const float height);
		void add_shape(std::shared_ptr<Shape> shape);
		void destroy_bodies();
		void simulate();
	};
}