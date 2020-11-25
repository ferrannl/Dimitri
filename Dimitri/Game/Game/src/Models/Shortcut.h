#pragma once
#include "../Events/InputEvent.h"
#include <memory>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	namespace Commands {
		class Command;
	}
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {		
		/**
		* \class Shortcut
		* \brief Class contains the methods to execute a command with a input key
		*/
		class Shortcut {
		private:
			/**
			* \brief An instance of the Command
			*/
			std::shared_ptr<Commands::Command> _command;

			/**
			* \brief An instance of the event that triggers the command
			*/
			Input::Enums::EventEnum _event;
		public:
			Shortcut(const std::shared_ptr<Commands::Command> command, Input::Enums::EventEnum event);

			/**
			* \brief Returns the command
			*/
			std::shared_ptr<Commands::Command> get_command() const;

			/**
			* \brief Returns the event
			*/
			const Input::Enums::EventEnum get_event() const;
		};
	}
}