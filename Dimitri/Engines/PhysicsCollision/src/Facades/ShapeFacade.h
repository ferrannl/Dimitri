#pragma once
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>
#include <vector>
#include <iostream>
#include <box2d\b2_body.h>

namespace Facades {
	float static RADIAN_IN_DEGREES = 57.3f;
	class __declspec(dllexport) ShapeFacade {
	private:
		std::shared_ptr<b2PolygonShape> _shape;
		std::shared_ptr<b2Body> _body;
	public:
		ShapeFacade();
		ShapeFacade(const std::string type, std::vector<std::pair<float, float>> positions);
		std::shared_ptr<b2Shape> get_shape() const;
		void add_body(std::shared_ptr<b2Body> body);
		float get_x()const;
		float get_y()const;
		void move_x(const int value)const;
		void move_y()const;
		float get_angle()const;
	};
}
