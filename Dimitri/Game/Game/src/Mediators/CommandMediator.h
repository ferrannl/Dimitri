#pragma once
#include "../Commands/CommandFactory.h"
#include "../Events/InputEvent.h"
#include <..\Game\Game\src\Enums\LevelStateEnum.h>
#include "BaseComponent.h"
#include <memory>
#include "../Controllers/MainController.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Mediators
	* \brief Namespace for the mediator pattern
	*/
	namespace Mediators {
		/**
		* \class CommandMediator
		* \brief Class contains the methods to mediate the commands
		*/
		class CommandMediator {
		private:
			std::unique_ptr<Commands::CommandFactory> _factory;

			CommandMediator(const std::shared_ptr<Controllers::MainController> main_controller);
			CommandMediator(const CommandMediator&) = default;
			CommandMediator& operator=(const CommandMediator&) = default;

			static std::unique_ptr<CommandMediator> _instance;
		public:
			/**
			* \brief A singleton instance of the CommandMediator
			*/
			static CommandMediator* instance();
			CommandMediator(CommandMediator&&) = delete;
			CommandMediator& operator=(CommandMediator&&) = delete;

			/**
			* \brief Initializes the singleton instance of this class with all commands
			*/
			static void init(const std::shared_ptr<Controllers::MainController> main_controller);

			void notify(const BaseComponent& sender, Events::InputEvent event);
			void notify(const BaseComponent& sender, Enums::LevelStateEnum event);
		};
	}
}