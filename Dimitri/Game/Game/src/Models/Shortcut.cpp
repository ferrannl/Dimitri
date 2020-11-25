#include "Shortcut.h"
#include "../Commands/Command.h"

namespace Game {
	namespace Models {
		Shortcut::Shortcut(const std::shared_ptr<Commands::Command> command, Input::Enums::EventEnum event) : _command{ command }, _event{ event } {}

		std::shared_ptr<Commands::Command> Shortcut::get_command() const
		{
			return _command;
		}

		const Input::Enums::EventEnum Shortcut::get_event() const
		{
			return _event;
		}
	}
}