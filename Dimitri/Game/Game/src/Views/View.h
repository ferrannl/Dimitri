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
			*	If view is currently being used or not
			*/
			bool _open;
		protected:
			/**
			*	Graphics Controller to interact with engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			/**
			*	Textures for current view
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* Add the textures to the _graphics_controller
			*/
			virtual void draw() = 0;			

			/**
			*	Sets _textures
			*/
			void set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures);

			/**
			*	Returns if view is open
			*/
			bool is_open() const;

			/**
			*	Sets _open
			*/
			void set_open(bool open);
		};
	}
}
