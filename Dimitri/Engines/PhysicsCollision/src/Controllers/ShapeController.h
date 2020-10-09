#pragma once
#include <vector>
#include "../Factories/ShapeFactory.h"
#include "../Models/Shape.h"
#include <iostream>

namespace Controllers {
	class __declspec(dllexport) ShapeController {
	private:
		std::shared_ptr<Factories::ShapeFactory> _shape_factory;
	public:
		ShapeController();
		std::shared_ptr<Models::Shape> create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic)const;
	};
}