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
		* \brief Class contains the methods to draw the View
		*/
		class View {
		private:
			/**
			* \brief If the View is currently being used or not
			*/
			bool _active;

			/**
			* \brief If the View is currently visible
			*/
			bool _visible;
		protected:
			/**
			* \brief An instance of the GraphicsController to interact with graphics engine
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;

			/**
			* \brief A list of the Textures for current View
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
		public:
			View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Adds the Textures to the _graphics_controller
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
			* \brief Returns if the View is active
			*/
			bool is_active() const;

			/**
			* \brief Sets _active
			*/
			void set_active(bool open);

			/**
			* \brief Returns the visible state of the View
			*/
			virtual bool is_visible() const;

			/**
			* \brief Sets _visible
			*/
			void set_visible(bool visible);

		};
	}
}
