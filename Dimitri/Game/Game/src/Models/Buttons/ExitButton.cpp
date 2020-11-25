#include "ExitButton.h"
#include "../../Commands/CommandFactory.h"

namespace Game {
	Models::Buttons::ExitButton::ExitButton(int x, int y, int z, int height, int width, Enums::StateEnum state, int scene_height) :
		Models::Button(x, y, z, height, width, state, scene_height) {}

	void Models::Buttons::ExitButton::interact()
	{
		Commands::CommandFactory::instance()->get_command("exit_game")->execute();
	}
}