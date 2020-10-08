#pragma once
#include "../Facades/ShapeFacade.h"
#include "Body.h"

namespace Models {
	class __declspec(dllexport) Shape {
	protected:
		Models::Body* _body;
		Facades::ShapeFacade* _shape_facade;
	public:
		bool is_dynamic;
		Shape();
		Shape(std::vector<std::pair<float, float>> positions);
		void add_body(Models::Body* body);
		Facades::ShapeFacade* get_shape_facade();
		float get_x();
		float get_y();
		float get_angle();
	};
}