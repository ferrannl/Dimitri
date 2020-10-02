#pragma once
#include "Shape.h"
#include "../Adapters/WorldAdapter.h"

namespace Models {
	class __declspec(dllexport) World {
	private:
		Adapters::WorldAdapter _worldAdapter;
	public:
		World();
		World(float width, float height);
		void add_shape(Shape shape, float x, float y);
		void simulate();
	};
}