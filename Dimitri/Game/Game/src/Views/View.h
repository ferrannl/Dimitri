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
			bool _active;
			/**
			*	If view is currently visible
			*/
			bool _visible;
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
			*	Returns if view is active
			*/
			bool is_active() const;

			/**
			*	Sets _active
			*/
			void set_active(bool open);

			/**
			*	Returns if view is visible
			*/
			virtual bool is_visible() const;

			/**
			*	Sets _visible
			*/
			void set_visible(bool visible);
		};
	}
}
