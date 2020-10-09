#pragma once
#include "../Facades/ShapeFacade.h"

namespace Models {
	class __declspec(dllexport) Shape {
	protected:
		Facades::ShapeFacade* _shape_facade;
	public:
		bool is_dynamic;
		Shape();
		Shape(std::vector<std::pair<float, float>> positions);
		Facades::ShapeFacade* get_shape_facade();
		float get_x();
		float get_y();
		void move_x(int value);
		void move_y();
		float get_angle();
	};
}
