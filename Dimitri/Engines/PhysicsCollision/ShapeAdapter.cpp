#include "ShapeAdapter.h"

ShapeAdapter::ShapeAdapter()
{
	_shape = nullptr;
}

ShapeAdapter::ShapeAdapter(std::string type, std::vector<std::pair<float, float>> position)
{
	int size = position.size();
	b2Vec2* vertices = new b2Vec2[size];
	/*for (int i = 0; i < size; i++)
	{
		auto temp = position[i+1];
		vertices[i].Set(position[i], position[i]);*/
	unsigned int counter = 0;
	for (std::vector<std::pair<float, float>>::iterator it = position.begin(); it != position.end(); ++it)
	{
		vertices[counter].Set(it->first, it->second);
		counter++;
	}
	/*}*/
	if (type == "polygon") {
		_shape = new b2PolygonShape{};
		auto temp = position;
		((b2PolygonShape*)_shape)->Set(vertices, size);
	}
}

b2Shape& ShapeAdapter::get_shape() const
{
	return *_shape;
}
