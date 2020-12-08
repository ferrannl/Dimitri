#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <vector>
#include <memory>
#include "../Models/Button.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		* \class CreditsController
		* \brief Class contains the methods to interact with credits view
		*/
		class CreditsController : public Utility::Interfaces::IObserver<Events::InputEvent> {
		private:
			/**
			* \brief A list of the Buttons
			*/
			std::vector<std::unique_ptr<Game::Models::Button>> _buttons;

			/**
			* \brief The height of the scene
			*/
			int _scene_height;

			/**
			* \brief The width of the scene
			*/
			int _scene_width;
		public:
			CreditsController(int sceneheight, int scenewidth);

			/**
			* \brief Loads the Buttons
			*/
			void load_buttons();

			/**
			* \brief Calls on click event on the buttons if clicked
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns the Textures from the Buttons
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

		};
	}
}
