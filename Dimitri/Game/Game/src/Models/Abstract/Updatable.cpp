#include "Updatable.h"

Game::Models::Updatable::Updatable(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : Models::Object(x, y, z, height, width, state, center)
{
}

void Game::Models::Updatable::set_speed(float speed)
{
	if (_angle < 0)
	{
		_angle = speed * -1;
	}
	else {
		_angle = speed;
	}
}
