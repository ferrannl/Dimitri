#pragma once
#include <string>
#include <exception>
namespace Graphics {
	namespace Exceptions {
		struct CannotLoadImage : public std::exception {
			const char* get() const throw () {
				return "Cannot load the image from the specified path";
			}
		};

		struct CannotCreateTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot create the texture from the generated surface";
			}
		};

		struct CannotCreateRenderer : public std::exception {
			const char* get() const throw () {
				return "Cannot create the renderer";
			}
		};

		struct SDLInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize sdl";
			}
		};

		struct TTFInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize sdl ttf";
			}
		};

		struct CannotCreateWindow : public std::exception {
			const char* get() const throw () {
				return "Cannot create the window with the given parameters";
			}
		};

		struct CannotRenderSpriteTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot render the sprite texture";
			}
		};

		struct CannotLoadFont : public std::exception {
			const char* get() const throw () {
				return "Cannot load font";
			}
		};
	}
}