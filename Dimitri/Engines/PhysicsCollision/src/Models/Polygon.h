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
* \namespace PhysicsCollision
* \brief Namespace for the physics collision engine
*/
namespace PhysicsCollision {
	/**
	* \namespace PhysicsCollision::Models
	* \brief Namespace for the models in the physics collision engine
	*/
	namespace Models {
		/**
		* \class Polygon
		* \brief Class contains the data for a polygon Shape
		*/
		class PHYSICSCOLLISION_API Polygon : public Shape {
		public:
			Polygon(float x, float y, float height, float width, bool is_dynamic, bool is_interactable, Enums::ShapeEnum type);
		};
		}
}
