#include "ShapeFactory.h"

std::shared_ptr<PhysicsCollision::Models::Shape> PhysicsCollision::Factories::ShapeFactory::create_shape(const std::string type,float x, float y, float width, float height, const bool is_dynamic)const
{
	if (type == "polygon") {
		return std::make_shared<PhysicsCollision::Models::Polygon>();
	}
}
