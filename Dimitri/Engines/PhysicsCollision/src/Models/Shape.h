#pragma once
#include "../Facades/ShapeFacade.h"
#include <iostream>
#include "../Enums/ShapeEnum.h"

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
	namespace Models {
		class PHYSICSCOLLISION_API Shape {
		private:
			float _x;
			float _y;
			float _width;
			float _height;
			bool _is_dynamic;
		protected:
			Enums::ShapeEnum _type;
			std::shared_ptr<Facades::ShapeFacade> _shape_facade;
		public:
			Shape();
			std::shared_ptr<Facades::ShapeFacade> get_shape_facade()const;
			Enums::ShapeEnum get_type()const;
			void set_type(Enums::ShapeEnum type);
			void set_x(float x);
			void set_y(float y);
			void set_width(float width);
			void set_height(float height);
			float get_x()const;
			float get_y()const;
			float get_width() const;
			float get_height() const;
			void move_x(const int value)const;
			void move_y()const;
			float get_angle()const;
			bool get_is_dynamic() const;
			void set_is_dynamic(bool is_dynamic);
		};
	}
}
