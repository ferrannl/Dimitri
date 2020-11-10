#include "View.h"

namespace Game {
	Views::View::View(float width, float height) : _width{ width }, _height{ height } {}

	std::vector<std::shared_ptr<Graphics::Models::Texture>> Views::View::get_textures() const
	{
		return _textures;
	}

	void Views::View::set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures)
	{
		_textures = textures;
	}

	void Views::View::add_texture(const std::shared_ptr<Graphics::Models::Texture>& texture)
	{
		_textures.push_back(texture);
	}

	bool Views::View::is_open() const {
		return _open;
	}

	void Views::View::set_open(bool open) {
		_open = open;
	}

	float Views::View::get_width() const
	{
		return _width;
	}

	void Views::View::set_width(float width)
	{
		_width = width;
	}

	float Views::View::get_height() const
	{
		return _height;
	}

	void Views::View::set_height(float height)
	{
		_height = height;
	}
}
