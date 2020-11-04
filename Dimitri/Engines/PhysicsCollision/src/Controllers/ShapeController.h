#pragma once
#include <vector>
#include "../Models/Shape.h"
#include "../Models/Polygon.h"
#include "../Models/Square.h"
#include <iostream>

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
* Namespace for the PhysicsCollision Engine
*/
namespace PhysicsCollision {
	/**
	* Namespace for the controllers
	*/
	namespace Controllers {
		/**
		* Contains the method to create a shape
		*/
		class PHYSICSCOLLISION_API ShapeController {
		public:
			ShapeController();
			/**
			* Creates the shape based on given type
			*/
			std::shared_ptr<Models::Shape> create_shape(const Enums::ShapeEnum type, float x, float y, float width, float height, const bool is_dynamic)const;
		};
	}
}
