#pragma once
#include <string>
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"
#include <iostream>

namespace PhysicsCollision {
	namespace Factories {
		class __declspec(dllexport) ShapeFactory {
		public:
			std::shared_ptr<Models::Shape> create_shape(const std::string type, float x, float y, float width, float height, const bool is_dynamic)const;
		};
	}
}
