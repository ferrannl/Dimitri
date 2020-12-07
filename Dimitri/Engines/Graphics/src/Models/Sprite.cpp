#include "Sprite.h"
using namespace Graphics;

Models::Sprite::Sprite(const float x, const float y, const float z, const float height, const float width, const float angle, const std::string& path, const Enums::FlipEnum flipstatus, const bool visible, const Models::Center center, int opacity) :
	Models::Texture(x, y, z, height, width, angle, path, visible, center, opacity)
{
	_flipstatus = flipstatus;
}

void Graphics::Models::Sprite::create_texture_facade()
{
	_facade = std::make_shared<Facades::SpriteFacade>(get_path(), get_opacity());
}

bool Graphics::Models::Sprite::matches(const std::shared_ptr<Models::Texture>& texture) const
{
	std::shared_ptr<Graphics::Models::Sprite> sprite = std::dynamic_pointer_cast<Graphics::Models::Sprite>(texture);
	if (sprite.get()) {
		return sprite->get_path() == get_path() &&
			sprite->get_opacity() == get_opacity();
	}
	return false;
}
