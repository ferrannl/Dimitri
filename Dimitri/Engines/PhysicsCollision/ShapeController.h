#pragma once

#include <vector>
#include "Shape.h"
#include "ShapeFactory.h"

class __declspec(dllexport) ShapeController
{
private:
	ShapeFactory* _shapeFactory;
public:
	ShapeController();
	Shape create_shape(std::string type, float x, float y, std::vector<std::pair<float, float>> position, bool is_dynamic);
};