#pragma once
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"
#include <iostream>

namespace PhysicsCollision {
	namespace Controllers {
		class __declspec(dllexport) ShapeController {
		private:
		public:
			ShapeController();
			std::shared_ptr<Models::Shape> create_shape(const Enums::ShapeEnum type, float x, float y, float width, float height, const bool is_dynamic)const;
		};
	}
}
