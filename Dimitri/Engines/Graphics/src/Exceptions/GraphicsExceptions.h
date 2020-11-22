#pragma once
#include <string>
#include <exception>

/**
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Exceptions
	* \brief Namespace for the exceptions in the graphics engine
	*/
	namespace Exceptions {
		/**
		* \struct CannotLoadImage
		* \brief Exception thrown if an SDL image cannot be loaded
		*/
		struct CannotLoadImage : public std::exception {
			const char* get() const throw () {
				return "Cannot load the image from the specified path";
			}
		};

		/**
		* \struct CannotCreateTexture
		* \brief Exception thrown if a Texture cannot be created
		*/
		struct CannotCreateTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot create the texture from the generated surface";
			}
		};

		/**
		* \struct CannotCreateRenderer
		* \brief Exception thrown if a renderer cannot be created
		*/
		struct CannotCreateRenderer : public std::exception {
			const char* get() const throw () {
				return "Cannot create the renderer";
			}
		};

		/**
		* \struct SDLInitFailed
		* \brief Exception thrown if SDL cannot be initialized
		*/
		struct SDLInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize sdl";
			}
		};
    
		/**
		* \struct TTFInitFailed
		* \brief Exception thrown if SDL_ttf cannot be initialized
		*/
		struct TTFInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize sdl ttf";
			}
		};


		/**
		* \struct CannotCreateWindow
		* \brief Exception thrown if a Window cannot be created
		*/
		struct CannotCreateWindow : public std::exception {
			const char* get() const throw () {
				return "Cannot create the window with the given parameters";
			}
		};

		/**
		* \struct CannotRenderSpriteTexture
		* \brief Exception thrown if a Texture cannot be rendered
		*/
		struct CannotRenderSpriteTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot render the sprite texture";
			}
		};

		/**
		* \struct CannotLoadFont
		* \brief Exception thrown if a font cannot be loaded
		*/
		struct CannotLoadFont : public std::exception {
			const char* get() const throw () {
				return "Cannot load font";
			}
		};
	}
}