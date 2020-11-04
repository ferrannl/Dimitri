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
* Namespace for the PhysicsCollision
*/
namespace PhysicsCollision {
	/**
	* Namespace for the models
	*/
	namespace Models {
		/**
		* Square model
		*/
		class PHYSICSCOLLISION_API Square : public Shape {
		public:
			Square();
		};
	}
}

