#include "Text.h"
using namespace Graphics;

Models::Text::Text(const std::string& text, const Color& color, const int x, const int y, const int z, const int height, const int width, const float angle, const std::string& path, const bool visible) :
	Models::Texture(x, y, z, height, width, angle, path, visible), _text{ text }, _color{ color} {}

const std::string Graphics::Models::Text::get_text() const
{
	return _text;
}

const Color Graphics::Models::Text::get_color() const
{
	return _color;
}

void Graphics::Models::Text::create_texture_facade()
{
	_facade = std::make_shared<Facades::TextFacade>(get_path(), get_text(), get_color(), get_height());
}

bool Graphics::Models::Text::matches(const std::shared_ptr<Models::Texture>& texture) const
{
	std::shared_ptr<Graphics::Models::Text> text = std::dynamic_pointer_cast<Graphics::Models::Text>(texture);
	if (text.get()) {
		return text->get_text() == get_text() &&
			text->get_path() == get_path() &&
			text->get_color().red == get_color().red &&
			text->get_color().green == get_color().green &&
			text->get_color().blue == get_color().blue &&
			text->get_height() == get_height();
	}
	return false;
}
