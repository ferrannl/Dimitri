#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>
#include "Command.h"
#include "../Controllers/MainController.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Commands
	* \brief Namespace for the commands in the game
	*/
	namespace Commands {
		/**
		* \class CommandFactory
		* \brief Class contains all commands
		*/
		class CommandFactory {
		private:
			/**
			* \brief An instance of the MainController
			*/
			std::shared_ptr<Controllers::MainController> _main_controller;

			/**
			* \brief A list of the Commands
			*/
			std::map<std::string, std::shared_ptr<Command>> _commands;
			CommandFactory(const CommandFactory&) = default;
			CommandFactory& operator=(const CommandFactory&) = default;

			static std::unique_ptr<CommandFactory> _instance;
		public:
			CommandFactory(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief A singleton instance of the CommandMediator
			*/
			static CommandFactory* instance();
			CommandFactory(CommandFactory&&) = delete;
			CommandFactory& operator=(CommandFactory&&) = delete;

			/**
			* \brief Initializes the singleton instance of this class with all commands
			*/
			static void init(const std::shared_ptr<Controllers::MainController> main_controller);

			/**
			* \brief Returns the Command by name
			*/
			const std::shared_ptr<Command> get_command(const std::string& command_name) const;
		};
	}
}