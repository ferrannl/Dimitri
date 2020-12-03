#include "Updatable.h"

Game::Models::Updatable::Updatable(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center, Game::Enums::TypeEnum type) : Models::Object(x, y, z, height, width, state, center)
{
	_type = type;
}

Game::Enums::TypeEnum Game::Models::Updatable::get_type()
{
	return _type;
}
