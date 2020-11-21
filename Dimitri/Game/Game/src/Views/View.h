#pragma once
#include <src\Controllers\GraphicsController.h>
#include <memory>
#include <vector>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Views
	* \brief Namespace for the views in the game
	*/
	namespace Views {
		/**
		* \class View
		* \brief Class contains the methods to draw the view
		*/
		class View {
		private:
			/**
			*	If the View is currently being used or not
			*/
			bool _active;

			/**
			*	If the View is currently visible
			*/
			bool _visible;
		protected:
			/**
			*	An instance of the GraphicsController to interact with graphics engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;

			/**
			*	A list of the Textures for current view
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Add the textures to the _graphics_controller
			*/
			virtual void draw();

			/**
			* \brief Sets _textures
			*/
			void set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures);

			/**
			* \brief Adds a Texture to _textures
			*/
			void add_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures);

			/**
			* \brief Returns if view is active
			*/
			bool is_active() const;

			/**
			* \brief Sets _active
			*/
			void set_active(bool open);

			/**
			* \brief Returns if the View is visible
			*/
			virtual bool is_visible() const;

			/**
			* \brief Sets _visible
			*/
			void set_visible(bool visible);

		};
	}
}
