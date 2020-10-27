#include "Sprite.h"
using namespace Graphics;

Models::Sprite::Sprite(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path, const Enums::FlipEnum flipstatus) :
	Models::Texture(x, y, x, height, width, angle, path)
{
	_flipstatus = flipstatus;
}

void Graphics::Models::Sprite::create_texture_facade()
{
	_facade = std::make_shared<Facades::SpriteFacade>(get_path());
}

bool Graphics::Models::Sprite::matches(const std::shared_ptr<Models::Texture>& texture) const
{
	auto sprite = std::dynamic_pointer_cast<Graphics::Models::Sprite>(texture);
	if (sprite) {
		return sprite.get()->get_path() == get_path();
	}
	return false;
}


