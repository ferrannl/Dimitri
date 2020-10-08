#include "SpriteRAII.h"

RAIIs::SpriteRAII::SpriteRAII(Models::Sprite* sprite) : _sprite{ sprite } {};

RAIIs::SpriteRAII::~SpriteRAII()
{
	delete _sprite;
}