#pragma once
#pragma warning( disable : 26812 )

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
	* \namespace PhysicsCollision::Enums
	* \brief Namespace for the enums in the physics collision engine
	*/
	namespace Enums {
		/**
		* Enum for the different shape types
		*/
		enum class PHYSICSCOLLISION_API ShapeEnum {
			Polygon, Circle, Square
		};
	}
}