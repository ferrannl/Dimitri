#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>
#include "../Models/IObject.h"

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
		* \class HomeView
		* \brief Class contains the methods to draw the home screen
		*/
		class HomeView : public View {
		public:
			HomeView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes Textures
			*/
			void init_textures();

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;

			/**
			* \brief Add the Textures to the _graphics_controller
			*/
			void draw() override;

			/**
			* \brief The background of the View
			*/
			std::shared_ptr<Graphics::Models::Texture> _background;

			/**
			* \brief The play button
			*/
			std::shared_ptr<Game::Models::IObject> _button_play_game;

			/**
			* \brief The exit button
			*/
			std::shared_ptr<Game::Models::IObject> _button_exit_game;
		};
	}
}
