#pragma once
#include <string>
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"
#include <iostream>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Factories {
	class PHYSICSCOLLISION_API ShapeFactory {
	public:
		std::shared_ptr<Models::Shape> create_shape(const std::string type, const std::vector<std::pair<float, float>> positions, const bool is_dynamic)const;
	};
}