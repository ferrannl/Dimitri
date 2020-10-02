#pragma once
#include <string>
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"

namespace Factories {
	class __declspec(dllexport) ShapeFactory {
	public:
		Models::Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic);
	};
}