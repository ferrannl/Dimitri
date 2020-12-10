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
			/**
			* \brief An instance of the CommandFactory
			*/
			std::unique_ptr<Commands::CommandFactory> _factory;

			CommandMediator(const std::shared_ptr<Controllers::MainController> main_controller);
			CommandMediator(const CommandMediator&) = default;
			CommandMediator& operator=(const CommandMediator&) = default;

			/**
			* \brief A singleton instance of the CommandMediator
			*/
			static std::unique_ptr<CommandMediator> _instance;

			void notify_buttons(const BaseComponent& sender, Events::InputEvent event, const std::map<Enums::ButtonEnum, std::string>& button_command);
		public:
			/**
			* \brief Returns the singleton instance
			*/
			static CommandMediator* instance();
			CommandMediator(CommandMediator&&) = delete;
			CommandMediator& operator=(CommandMediator&&) = delete;

			/**
			* \brief Initializes the singleton instance of this class with all commands
			*/
			static void init(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Executes a Command based on the sender and the input event
			*/
			void notify(const BaseComponent& sender, Events::InputEvent event);

			/**
			* \brief Executes a Command based on the sender and the level state enum
			*/
			void notify(const BaseComponent& sender, Enums::LevelStateEnum event);
		};
	}
}