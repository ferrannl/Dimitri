#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <vector>
#include <memory>
#include "../Mediators/BaseComponent.h"
#include "../Models/Settings/Settings.h"
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
		* \class SaveGameController
		* \brief Class contains the methods to interact with save game view
		*/
		class SaveGameController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Mediators::BaseComponent {
		private:
			/**
			* \brief The height of the scene
			*/
			int _scene_height;

			/**
			* \brief The width of the scene
			*/
			int _scene_width;

			/**
			* \brief Returns save game string
			*/
			std::string get_text_for_save(Game::Models::Settings settings) const;
		public:
			SaveGameController(int sceneheight, int scenewidth);

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
