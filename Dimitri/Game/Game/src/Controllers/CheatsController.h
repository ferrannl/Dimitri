#pragma once
#include "../Events/InputEvent.h"
#include <src\Interfaces\IObservable.h>
#include <src\Models\Texture.h>
#include <..\Game\Game\src\Events\InputEvent.h>
#include "../Models/LevelCheatSettings.h"
#include "../Models/Check.h"
#include "../Models/Buttons/CheckBox.h"
#include <src\Helpers\BasePathHelper.h>
#include <src\Models\Color.h>
#include <src\Models\Text.h>
#include <src\Models\Sprite.h>

#include <memory>
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
		* \class LevelController
		* \brief Class CheatsController contains the methods to interact with the cheats
		*/
		class CheatsController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Game::Models::Check, public std::enable_shared_from_this<CheatsController> {
		private:
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;

			std::shared_ptr<Game::Models::LevelCheatSettings> _settings;

			/**
			* \brief A list of the Buttons
			*/
			std::vector<std::unique_ptr<Game::Models::Button>> _buttons;
		public:
			CheatsController();

			void initialize_textures(int height, int width);

			/**
			* \brief Returns a list of all Textures in the cheatsview
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			* \brief Returns cheat settings
			*/
			std::shared_ptr<Game::Models::LevelCheatSettings> get_cheat_settings() const;

			/**
			* \brief Receives updates from InputController
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Receives updates from checkbox
			*/
			void check(int check_code);
		};
	}
}