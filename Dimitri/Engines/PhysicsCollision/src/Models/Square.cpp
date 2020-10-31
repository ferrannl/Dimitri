#include "Square.h"
using namespace PhysicsCollision;

Models::Square::Square() {
	_type == Enums::ShapeEnum::Square;
}

Models::Square::Square(bool is_dynamic) {
	this->is_dynamic = is_dynamic;
	_type == Enums::ShapeEnum::Square;
}