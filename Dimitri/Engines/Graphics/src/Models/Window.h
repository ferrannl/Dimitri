#pragma once
#include "../Facades/WindowFacade.h"
#include "Text.h"

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

/**
* Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* Namespace for the models
	*/
	namespace Models {
		/**
		* Holds the data the window needs to be generated.
		*/
		class GRAPHICS_API Window {
		private:
			/**
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
			std::shared_ptr<Facades::WindowFacade> _facade;

			/**
			* Holds all the textures displayed in the window
			*/
			std::vector<std::shared_ptr<Texture>> _textures;

			/**
			* Returns a Texture if a matching Texture already exists
			*/
			std::shared_ptr<Models::Texture> get_matching_texture(const std::shared_ptr<Models::Texture>& texture) const;
		public:
			Window(const std::string& title, const int height, const int width);

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
			* Adds the Texture to _textures
			*/
			void add_texture(const std::shared_ptr<Texture>& texture);

			/**
			* Removes the Texture from _textures
			*/
			void remove_texture(const std::shared_ptr<Texture>& texture);

			/**
			* Clears all textures from _textures
			*/
			void clear_textures();

			/**
			* Returns the textures list of this model
			*/
			std::vector<std::shared_ptr<Texture>> get_textures() const;

			/**
			* Returns the height of this window
			*/
			int get_height() const;

			/**
			* Returns the width of this window
			*/
			int get_width() const;

			/**
			* Returns the title of this window
			*/
			const std::string get_title() const;

			std::shared_ptr<Facades::WindowFacade> get_facade() const;

			/**
			* Updates camera position
			*/
			void set_camera_pos(const int x, const int y);

			/**
			* Sets level size
			*/
			void set_level_size(const int height, const int width);
		};
	}
}