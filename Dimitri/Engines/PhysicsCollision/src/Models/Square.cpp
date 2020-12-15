#include "Square.h"
using namespace PhysicsCollision;

Models::Square::Square(float x, float y, float height, float width, const bool is_dynamic,const bool is_interactable, const Enums::ShapeEnum type) : Shape(x, y, height, width, is_dynamic, is_interactable, type)
{
}