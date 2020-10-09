#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

namespace Models {
	class __declspec(dllexport) World {
	private:
		Facades::WorldFacade _world_facade;
	public:
		World();
		World(float width, float height);
		void add_shape(Shape* shape, float x, float y);
		void simulate();
	};
}