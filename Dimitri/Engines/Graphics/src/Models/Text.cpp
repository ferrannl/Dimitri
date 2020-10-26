#include "Text.h"
using namespace Graphics;

Models::Text::Text(const std::string text, const uint8_t color_red, uint8_t color_green, const uint8_t color_blue, const int size, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path) :
	Models::Texture(x, y, x, height, width, angle, path), _text{ text }, _color_red{ color_red }, _color_green{ color_green }, _color_blue{ color_blue }, _size{ size } {}

const std::string Graphics::Models::Text::get_text() const
{
	return _text;
}
