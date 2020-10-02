#pragma once
#include <SDL.h>

namespace Models
{
	class __declspec(dllexport) Texture
	{
	private:
		const char* _path;
		SDL_Texture* _texture;
	public:
		Texture(const char* path, SDL_Texture* texture)
			: _path{ path }, _texture{ texture } { }

		const char* get_path();
		SDL_Texture* get_texture();
	};
}