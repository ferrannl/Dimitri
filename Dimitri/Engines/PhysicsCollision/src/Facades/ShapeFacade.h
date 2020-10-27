#pragma once
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>
#include <vector>
#include <iostream>
#include <box2d\b2_body.h>

namespace PhysicsCollision {
	namespace Facades {
		float static RADIAN_IN_DEGREES = 57.3f;
		class __declspec(dllexport) ShapeFacade {
		private:
			b2Body* _body;
		public:
			ShapeFacade();
			void add_body(b2Body* body);
			b2Body* get_body()const;
			void move_x(const int value)const;
			void move_y()const;
			float get_angle()const;
		};
	}
}
