#pragma once
#include <vector>
#include "../Factories/ShapeFactory.h"
#include "../Models/Shape.h"
#include <iostream>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Controllers {
	class PHYSICSCOLLISION_API ShapeController {
	private:
		std::shared_ptr<Factories::ShapeFactory> _shape_factory;
	public:
		ShapeController();
		std::shared_ptr<Models::Shape> create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic)const;
	};
}