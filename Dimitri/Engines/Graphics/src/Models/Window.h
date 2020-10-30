#pragma once
#include "../Facades/WindowFacade.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Graphics {

	/**
	* Namespace for all the models in the project
	*/
	namespace Models {
		/**
		* Holds the data the window needs to be generated.
		*/
		class GRAPHICS_API Window {
		private:
			/**
			*
			* Height of the window
			*/
			int _height;

			/**
			* Width of the window
			*/
			int _width;

			/**
			* Title of the window, displayed in the frame
			*/
			const std::string _title;

			/**
			* Holds all functions and references to sdl which can be used to create/destroy/update windows and render sprites
			*/
			std::unique_ptr<Facades::WindowFacade> _facade;

			/**
			* Holds all the sprites displayed in the window
			*/
			std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> _sprites;

		public:
			Window(const std::string title, const int height, const int width);

			/**
			* Return int is used to check if sdl is initialized.
			* if int is < 0, the initialization failed
			*/
			int create();

			/**
			* Updates a window
			*/
			void update();

			/**
			* Destroys a window
			*/
			void destroy();

			/**
			* Sets the _sprites vector of this model
			*/
			void set_sprites(const std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> sprites);

			/**
			* Returns the sprites list of this model
			*/
			std::shared_ptr<std::vector<std::unique_ptr<Sprite>>> get_sprites() const;

			/**
			* Returns the height of this window
			*/
			int get_height() const;

			/**
			* Returns the width of this window
			*/
			int get_width() const;

			/**
			* Returns the width of this window
			*/
			const std::string get_title() const;
		};
	}
}