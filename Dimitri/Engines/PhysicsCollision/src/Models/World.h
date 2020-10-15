#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

namespace Models {
	class __declspec(dllexport) World {
	private:
		Facades::WorldFacade _world_facade;
	public:
		std::shared_ptr<std::vector<std::shared_ptr<Shape>>> _shapes;
		World();
		World(const float width, const float height);
		//void add_shape_to_shapes(std::shared_ptr<Shape> shape);
		void add_shape(std::shared_ptr<Shape> shape, const float x, const float y);
		void destroy_shapes();
		void simulate();
	};
}