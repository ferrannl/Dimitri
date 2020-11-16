#pragma once
#include <map>
#include "Shape.h"
#include <vector>
#include "../Facades/ShapeFacade.h"

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
		* Square model
		*/
		class PHYSICSCOLLISION_API Square : public Shape {
		public:
			Square(const int x, const int y, const int height, const int width, const bool is_dynamic, const bool is_interactable, const Enums::ShapeEnum type);
		};
	}
}

