#include "Polygon.h"
using namespace PhysicsCollision;

Models::Polygon::Polygon(float x, float y, float height, float width, bool is_dynamic, bool is_interactable, const Enums::ShapeEnum type) : Shape(x, y, height, width, is_dynamic, is_interactable, type)
{
}