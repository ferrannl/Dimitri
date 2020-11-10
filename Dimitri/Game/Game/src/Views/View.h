#pragma once
#include <src\Controllers\GraphicsController.h>
#include <thread>
#include <memory>
#include <vector>
/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the view using the graphics controller
		*/
		class View {
		private:
			/**
			*	Textures for current view
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
			/**
			*	If view is currently being used or not
			*/
			bool _open;
			/**
			*	Widht of view
			*/
			float _width;

			/**
			*	Height of view
			*/
			float _height;
		public:
			View(float width, float height);
			/**
			*	Returns _textures
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			*	Sets _textures
			*/
			void set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures);

			/**
			*	add texture to _textures
			*/
			void add_texture(const std::shared_ptr<Graphics::Models::Texture>& texture);

			/**
			*	Returns is view is open
			*/
			bool is_open() const;

			/**
			*	Sets _open
			*/
			void set_open(bool open);

			/**
			*	Returns _width
			*/
			float get_width() const;

			/**
			*	Sets _width
			*/
			void set_width(float width);

			/**
			*	Returns _height
			*/
			float get_height() const;

			/**
			*	Sets _height
			*/
			void set_height(float height);
		};
	}
}
