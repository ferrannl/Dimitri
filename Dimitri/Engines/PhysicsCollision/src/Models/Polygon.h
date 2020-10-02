#pragma once
#include <map>
#include "Shape.h"
#include <vector>
#include "../Adapters/ShapeAdapter.h"

namespace Models {
	class __declspec(dllexport) Polygon : public Shape {
	public:
		Polygon();
		Polygon(std::vector<std::pair<float, float>> positions, bool is_dynamic);
		void add_body(b2Body* body);
	};
}