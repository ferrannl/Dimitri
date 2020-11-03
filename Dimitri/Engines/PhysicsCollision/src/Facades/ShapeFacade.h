#pragma once
#include <box2d/b2_shape.h>
#include <box2d/b2_polygon_shape.h>
#include <string>
#include <vector>
#include <iostream>
#include <box2d\b2_body.h>

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else
#define PHYSICSCOLLISION_API __declspec(dllimport)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace PhysicsCollision {
	namespace Facades {
		float static RADIAN_IN_DEGREES = 57.3f;
		class PHYSICSCOLLISION_API ShapeFacade {
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
