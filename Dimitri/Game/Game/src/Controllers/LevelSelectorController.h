#pragma once
#include <src\Interfaces\IObserver.h>
#include "../Events/InputEvent.h"
#include <vector>
#include <memory>
#include "../Mediators/BaseComponent.h"

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
		* \class LevelSelectorController
		* \brief Class contains the methods to interact with level selector view
		*/
		class LevelSelectorController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Mediators::BaseComponent {
		private:
			/**
			* \brief The height of the scene
			*/
			int _scene_height;

			/**
			* \brief The width of the scene
			*/
			int _scene_width;
		public:
			LevelSelectorController(int sceneheight, int scenewidth);

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
