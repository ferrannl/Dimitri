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
			* \brief A list of the Commands
			*/
			std::map<std::string, std::unique_ptr<Command>> _commands;
			
		public:
			CommandFactory(const std::shared_ptr<Controllers::MainController> main_controller);			

			/**
			* \brief Returns the Command by name
			*/
			Command* get_command(const std::string& command_name) const;
		};
	}
}