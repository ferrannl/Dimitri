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
/**
* Namespace for the PhysicsCollision engine
*/
namespace PhysicsCollision {
	/**
	* Namespace for the Facades
	*/
	namespace Facades {
		/**
		* Variable for calculating the angle
		*/
		float static RADIAN_IN_DEGREES = 57.3f;
		/**
		* Namespace for the Enums
		*/
		class PHYSICSCOLLISION_API ShapeFacade {
		private:
			/**
			* Box2D body to add to each shape
			*/
			b2Body* _body;
		public:
			ShapeFacade();
			/**
			* Method for adding the body 
			*/
			void add_body(b2Body* body);
			/**
			* Getter method which returns the body
			*/
			b2Body* get_body()const;
			/**
			* Method to move the shape horizontally which needs 1 or -1 to decide which direction to move to
			*/
			void move_x(const int value)const;
			/**
			* Method to move the shape vertically
			*/
			void move_y()const;
			/**
			* Method which returns the angle of a shape
			*/
			float get_angle()const;
		};
		}
}
