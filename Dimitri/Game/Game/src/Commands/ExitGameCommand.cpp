#include "ExitGameCommand.h"
#include <stdlib.h>

namespace Game {
	namespace Commands {
		ExitGameCommand::ExitGameCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}

		void ExitGameCommand::execute()
		{
			exit(0);
		}
	}
}
