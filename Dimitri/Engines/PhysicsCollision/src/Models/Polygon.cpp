#include "Polygon.h"
using namespace PhysicsCollision;

Models::Polygon::Polygon(const float x, const float y, const float height, const float width, const bool is_dynamic, const bool is_interactable, const Enums::ShapeEnum type) : Shape(x, y, height, width, is_dynamic, is_interactable, type)
{
}