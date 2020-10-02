#pragma once
#include <vector>
#include "../Factories/ShapeFactory.h"
#include "../Models/Shape.h"

namespace Controllers {
	class __declspec(dllexport) ShapeController {
	private:
		Factories::ShapeFactory* _shapeFactory;
	public:
		ShapeController();
		Models::Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> positions, bool is_dynamic);
	};
}