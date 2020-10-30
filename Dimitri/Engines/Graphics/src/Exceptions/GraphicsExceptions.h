#pragma once
#include <string>
#include <exception>

namespace Graphics {
	/**
	* Namespace for all the Exceptions in the project
	*/
	namespace Exceptions {
		/**
		* Thrown when an image cannot be loaded
		*/
		struct CannotLoadImage : public std::exception {
			const char* get() const throw () {
				return "Cannot load the image from the specified path";
			}
		};

		/**
		* Thrown when an texture cannot be created
		*/
		struct CannotCreateTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot create the texture from the generated surface";
			}
		};

		/**
		* Thrown when an renderer cannot be created
		*/
		struct CannotCreateRenderer : public std::exception {
			const char* get() const throw () {
				return "Cannot create the renderer";
			}
		};

		/**
		* Thrown when SDL cannot be initialized
		*/
		struct SDLInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize sdl";
			}
		};

		/**
		* Thrown when an window cannot be created
		*/
		struct CannotCreateWindow : public std::exception {
			const char* get() const throw () {
				return "Cannot create the window with the given parameters";
			}
		};

		/**
		* Thrown when an texture cannot be rendered
		*/
		struct CannotRenderSpriteTexture : public std::exception {
			const char* get() const throw () {
				return "Cannot render the sprite texture";
			}
		};
	}
}