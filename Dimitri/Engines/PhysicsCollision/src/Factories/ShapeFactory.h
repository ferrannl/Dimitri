#pragma once
#include <string>
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"
#include <iostream>

namespace Factories {
	class __declspec(dllexport) ShapeFactory {
	public:
		std::shared_ptr<Models::Shape> create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic)const;
	};
}