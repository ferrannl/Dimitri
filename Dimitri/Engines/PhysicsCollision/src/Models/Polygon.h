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
		* Polygon Model
		*/
		class PHYSICSCOLLISION_API Polygon : public Shape {
		public:
			Polygon(int x, int y, int height, int width, bool is_dynamic, bool is_interactable, Enums::ShapeEnum type);
		};
		}
}
