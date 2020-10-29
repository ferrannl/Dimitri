#include "Text.h"
using namespace Graphics;

Models::Text::Text(const std::string text, const uint8_t color_red, uint8_t color_green, const uint8_t color_blue, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path) :
	Models::Texture(x, y, x, height, width, angle, path), _text{ text }, _color_red{ color_red }, _color_green{ color_green }, _color_blue{ color_blue } {}

const std::string Graphics::Models::Text::get_text() const
{
	return _text;
}

const uint8_t Graphics::Models::Text::get_color_red() const
{
	return _color_red;
}

const uint8_t Graphics::Models::Text::get_color_green() const
{
	return _color_green;
}

const uint8_t Graphics::Models::Text::get_color_blue() const
{
	return _color_blue;
}

void Graphics::Models::Text::create_texture_facade()
{
	_facade = std::make_shared<Facades::TextFacade>(get_path(), get_text(), get_color_red(), get_color_green(), get_color_blue(), get_height());
}

bool Graphics::Models::Text::matches(const std::shared_ptr<Models::Texture>& texture) const
{
	std::shared_ptr<Graphics::Models::Text> text = std::dynamic_pointer_cast<Graphics::Models::Text>(texture);
	if (text.get()) {
		return text.get()->get_path() == get_path() &&
			text.get()->get_color_red() == get_color_red() &&
			text.get()->get_color_green() == get_color_green() &&
			text.get()->get_color_blue() == get_color_blue() &&
			text.get()->get_width() == get_width() &&
			text.get()->get_height() == get_height();
	}
	return false;
}
