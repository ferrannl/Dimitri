#include "Sprite.h"
using namespace Graphics;

Models::Sprite::Sprite(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path, const Enums::FlipEnum flipstatus) :
	Models::Texture(x, y, x, height, width, angle, path)
{
	_flipstatus = flipstatus;
}


