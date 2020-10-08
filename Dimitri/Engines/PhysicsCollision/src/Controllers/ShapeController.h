#pragma once
#include <vector>
#include "../Factories/ShapeFactory.h"
#include "../Models/Shape.h"

namespace Controllers {
	class __declspec(dllexport) ShapeController {
	private:
		Factories::ShapeFactory* _shape_factory;
	public:
		ShapeController();
		Models::Shape* create_shape(std::string type, std::vector<std::pair<float, float>> positions, bool is_dynamic);
	};
}