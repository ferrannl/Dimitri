#pragma once
#include <vector>
#include "../Factories/ShapeFactory.h"
#include "../Models/Shape.h"
#include <iostream>

namespace PhysicsCollision {
	namespace Controllers {
		class __declspec(dllexport) ShapeController {
		private:
			std::shared_ptr<PhysicsCollision::Factories::ShapeFactory> _shape_factory;
		public:
			ShapeController();
			std::shared_ptr<PhysicsCollision::Models::Shape> create_shape(const std::string type, float x, float y, float width, float height, const bool is_dynamic)const;
		};
	}
}
