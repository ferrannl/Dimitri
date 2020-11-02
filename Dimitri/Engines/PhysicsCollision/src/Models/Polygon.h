#pragma once
#include <map>
#include "Shape.h"
#include <vector>
#include "../Facades/ShapeFacade.h"

namespace PhysicsCollision {
	namespace Models {
		class __declspec(dllexport) Polygon : public Shape {
		public:
			Polygon();
		};
	}
}