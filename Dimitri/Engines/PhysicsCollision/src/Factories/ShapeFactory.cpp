#include "ShapeFactory.h"
using namespace PhysicsCollision;

std::shared_ptr<Models::Shape> Factories::ShapeFactory::create_shape(const std::string type,float x, float y, float width, float height, const bool is_dynamic)const
{
	if (type == "polygon") {
		return std::make_shared<Models::Polygon>();
	}
}
