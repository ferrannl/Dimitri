#include "Text.h"
using namespace Graphics;

Models::Text::Text(const std::string& text, const Color& color, const float x, const float y, const float z, const float height, const float width, const float angle, const std::string& path, const bool visible, const Models::Center center, const bool is_dynamic, int opacity) :
	Models::Texture(x, y, z, height, width, angle, path, visible, center, is_dynamic, opacity), _text{ text }, _color{ color} {}

const std::string Models::Text::get_text() const
{
	return _text;
}

const Models::Color Models::Text::get_color() const
{
	return _color;
}

void Models::Text::create_texture_facade()
{
	_facade = std::make_shared<Facades::TextFacade>(get_path(), get_text(), get_color(), get_height(), get_opacity());
}

bool Models::Text::matches(const std::shared_ptr<Models::Texture>& texture) const
{
	std::shared_ptr<Models::Text> text = std::dynamic_pointer_cast<Models::Text>(texture);
	if (text.get()) {
		return text->get_text() == get_text() &&
			text->get_path() == get_path() &&
			text->get_color().red == get_color().red &&
			text->get_color().green == get_color().green &&
			text->get_color().blue == get_color().blue &&
			text->get_height() == get_height() &&
			text->get_opacity() == get_opacity();
	}
	return false;
}
