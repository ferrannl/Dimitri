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
/**
* Namespace for the PhysicsCollision engine
*/
namespace PhysicsCollision {
	/**
	* Namespace for the Models
	*/
	namespace Models {
		/**
		* Shape model for creating shapes
		*/
		class PHYSICSCOLLISION_API Shape {
		private:
			/**
			* X position of a shape
			*/
			float _x;
			/**
			* Y position of a shape
			*/
			float _y;
			/**
			* Width of a shape
			*/
			float _width;
			/**
			* Height of a shape
			*/
			float _height;
			/**
			* Is dynamic boolean of a shape
			*/
			bool _is_dynamic;
			bool _is_interactable;
		protected:
			/**
			* Shape type
			*/
			Enums::ShapeEnum _type;
			/**
			* Shape facade of a shape
			*/
			std::shared_ptr<Facades::ShapeFacade> _shape_facade;
		public:
			Shape();
			/**
			* Returns the ShapeFacade from a shape
			*/
			std::shared_ptr<Facades::ShapeFacade> get_shape_facade()const;
			/**
			* Returns the type from a shape
			*/
			Enums::ShapeEnum get_type()const;
			/**
			* Sets the type of a shape
			*/
			void set_type(Enums::ShapeEnum type);
			/**
			* Sets the x position of a shape
			*/
			void set_x(float x);
			/**
			* Set the y position of a shape
			*/
			void set_y(float y);
			/**
			* Set the width of a shape
			*/
			void set_width(float width);
			/**
			* Set the height of a shape
			*/
			void set_height(float height);
			/**
			* Returns the x position of a shape
			*/
			float get_x()const;
			/**
			* Returns the y position of a shape
			*/
			float get_y()const;
			/**
			* Returns the width of a shape
			*/
			float get_width() const;
			/**
			* Returns the height of a shape
			*/
			float get_height() const;
			/**
			* Move the x position of a shape based on value. -1 or 1 means left or right
			*/
			void move_x(const int value)const;
			/**
			* Move the y position of a shape
			*/
			void move_y()const;
			/**
			* Returns the angle of a shape
			*/
			float get_angle()const;
			/**
			* Returns if a shape is dynamic
			*/
			bool get_is_dynamic() const;
			bool get_is_interactable() const;
			/**
			* Sets the dynamic property of a shape
			*/
			void set_is_dynamic(bool is_dynamic);

			void set_is_interactable(bool is_interactable);
		};
	}
}
