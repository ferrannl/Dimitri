#include "Sprite.h"
using namespace Graphics;

Models::Sprite::Sprite(float x, float y, float z, float height, float width, float angle, const std::string& path, Enums::FlipEnum flipstatus, bool visible, const Models::Center& center, bool is_dynamic, int opacity) :
	Models::Texture(x, y, z, height, width, angle, path, visible, center, is_dynamic, opacity)
{
	_flipstatus = flipstatus;
}

void Graphics::Models::Sprite::create_texture_facade()
{
	_facade = std::make_shared<Facades::SpriteFacade>(get_path(), get_opacity());
}

bool Graphics::Models::Sprite::matches(const std::shared_ptr<Models::Texture> texture) const
{
	std::shared_ptr<Graphics::Models::Sprite> sprite = std::dynamic_pointer_cast<Graphics::Models::Sprite>(texture);
	if (sprite.get()) {
		return sprite->get_path() == get_path() &&
			sprite->get_opacity() == get_opacity();
	}
	return false;
}
