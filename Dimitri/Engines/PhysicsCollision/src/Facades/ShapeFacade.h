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
		b2Body* _body;
	public:
		ShapeFacade();
		ShapeFacade(const std::string type, float width, float height);
		std::shared_ptr<b2PolygonShape> get_shape() const;
		void add_body(b2Body* body);
		float get_x()const;
		float get_y()const;
		void move_x(const int value)const;
		void move_y()const;
		float get_angle()const;
	};
}
