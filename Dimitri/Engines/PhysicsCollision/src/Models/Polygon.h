#pragma once
#include <map>
#include "Shape.h"
#include <vector>
#include "../Facades/ShapeFacade.h"

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Models {
	class PHYSICSCOLLISION_API Polygon : public Shape {
	public:
		Polygon();
		Polygon(const std::vector<std::pair<float, float>> positions, bool is_dynamic);
	};
}