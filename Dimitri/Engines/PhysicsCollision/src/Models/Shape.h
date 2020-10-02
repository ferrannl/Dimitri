#pragma once
#include "../Adapters/ShapeAdapter.h"

namespace Models {
	class __declspec(dllexport) Shape {
	public:
		bool is_dynamic;
		Adapters::ShapeAdapter* shapeAdapter;
		Shape();
		Shape(std::vector<std::pair<float, float>> positions);
		void add_body(b2Body* body);
		float get_x();
		float get_y();
	};
}