#pragma once
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>
#include <vector>
#include <box2d\b2_body.h>

namespace Facades {
	class __declspec(dllexport) ShapeFacade {
	private:
		b2Shape* _shape;
	public:
		ShapeFacade();
		ShapeFacade(std::string type, std::vector<std::pair<float, float>> positions);
		b2Shape* get_shape() const;
	};
}