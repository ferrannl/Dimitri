#pragma once
#include <string>
#include <vector>
#include <iostream>

struct b2Body;

/**
* \namespace PhysicsCollision
* \brief Namespace for the physics collision engine
*/
namespace PhysicsCollision {
	/**
	* \namespace PhysicsCollision::Facades
	* \brief Namespace for the facades in the physics collision engine
	*/
	namespace Facades {
		/**
		* \var RADIAN_IN_DEGREES
		* Variable for calculating the angle from radians to degrees
		*/
		float static RADIAN_IN_DEGREES = 57.3f;
		/**
		* \class ShapeFacade
		* \brief Class contains the methods to handle the shapes using Box2d
		*/
		class ShapeFacade {
		private:
			/**
			* \brief An instance of a Box2D body
			*/
			b2Body* _body;
		public:
			ShapeFacade();

			/**
			* \brief Adds a body
			*/
			void add_body(b2Body* body);

			/**
			* \brief Returns the body
			*/
			b2Body* get_body() const;

			/**
			* \brief Move the X position
			* \param value -1 is left, 1 is right
			*/
			void move_x(float value) const;

			/**
			* \brief Move the Y position
			*/
			void move_y() const;

			/**
			* \brief Returns the angle
			*/
			float get_angle() const;
		};
		}
}
