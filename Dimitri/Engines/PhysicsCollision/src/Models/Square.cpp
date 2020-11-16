#include "Square.h"
using namespace PhysicsCollision;

Models::Square::Square(int x, int y, int height, int width, bool is_dynamic,bool is_interactable, Enums::ShapeEnum type) : Shape(x, y, height, width, is_dynamic, is_interactable, type)
{
}