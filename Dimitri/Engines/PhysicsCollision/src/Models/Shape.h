#pragma once
#include "../Facades/ShapeFacade.h"
#include <iostream>

namespace Models {
	class __declspec(dllexport) Shape {
	protected:
		std::shared_ptr<Facades::ShapeFacade> _shape_facade;
	public:
		bool is_dynamic;
		Shape();
		Shape(const std::vector<std::pair<float, float>> positions, bool is_dynamic);
		std::shared_ptr<Facades::ShapeFacade> get_shape_facade()const;
		float get_x()const;
		float get_y()const;
		void move_x(const int value)const;
		void move_y()const;
		float get_angle()const;
	};
}
