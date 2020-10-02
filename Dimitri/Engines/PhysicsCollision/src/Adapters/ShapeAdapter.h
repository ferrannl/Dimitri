#pragma once
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>
#include <vector>
#include <box2d\b2_body.h>

namespace Adapters {
	class __declspec(dllexport) ShapeAdapter {
	private:
		b2Shape* _shape;
		b2Body* _body;
	public:
		ShapeAdapter();
		ShapeAdapter(std::string type, std::vector<std::pair<float, float>> positions);
		b2Shape& get_shape() const;
		void add_body(b2Body* body);
		float get_x();
		float get_y();
	};
}