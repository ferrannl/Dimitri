#include "Polygon.h"
using namespace PhysicsCollision;

Models::Polygon::Polygon(int x, int y, int height, int width, bool is_dynamic, bool is_interactable, Enums::ShapeEnum type) : Shape(x, y, height, width, is_dynamic, is_interactable, type)
{
}