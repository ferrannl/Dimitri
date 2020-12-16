#pragma once
#include <src\Models\Texture.h>
#include "../Models/Settings/CheatsSettings.h"
#include <src\Helpers\BasePathHelper.h>
#include <src\Models\Color.h>
#include <src\Models\Text.h>
#include <src\Models\Sprite.h>
#include "../Mediators/BaseComponent.h"
#include <memory>
#include "../Models/Button.h"
#include <src\Interfaces\IObserver.h>

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
		* \class CheatsController
		* \brief Class CheatsController contains the methods to interact with the cheats
		*/
		class CheatsController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Mediators::BaseComponent {
		private:
			/**
			* \brief A list of the textures in cheats view
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;

			/**
			* \brief The cheat settings
			*/
			std::shared_ptr<Game::Models::CheatsSettings> _settings;

		public:
			CheatsController();

			/**
			* \brief Loads textures
			*/
			void initialize_textures(float height, float width);

			/**
			* \brief Receives updates from InputController
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns a list of all Textures in the cheatsview
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			* \brief Returns cheat settings
			*/
			const std::shared_ptr<Game::Models::CheatsSettings>& get_cheat_settings() const;
		};
	}
}