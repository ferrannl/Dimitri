#include "CommandFactory.h"
#include "ExitGameCommand.h"
#include "LoadLevelCommand.h"
#include "OpenCreditsViewCommand.h"
#include "OpenHelpViewCommand.h"
#include "OpenHomeViewCommand.h"
#include "ToggleFpsViewCommand.h"
#include "PlayerMoveLeftCommand.h"
#include "PlayerMoveRightCommand.h"
#include "PlayerJumpCommand.h"
#include "PlayerInteractCommand.h"
#include "LevelPauseCommand.h"

namespace Game {
	namespace Commands {
		std::unique_ptr<CommandFactory> CommandFactory::_instance{ nullptr };

		CommandFactory::CommandFactory(const std::shared_ptr<Controllers::MainController> main_controller) : _main_controller{ main_controller } {
			_commands.insert(std::make_pair("exit_game", std::make_shared<ExitGameCommand>(main_controller)));
			_commands.insert(std::make_pair("load_level", std::make_shared<LoadLevelCommand>(main_controller)));
			_commands.insert(std::make_pair("open_credits_view", std::make_shared<OpenCreditsViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_help_view", std::make_shared<OpenHelpViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_home_view", std::make_shared<OpenHomeViewCommand>(main_controller)));
			_commands.insert(std::make_pair("toggle_view", std::make_shared<ToggleFpsViewCommand>(main_controller)));
			_commands.insert(std::make_pair("player_move_left", std::make_shared<PlayerMoveLeftCommand>(main_controller)));
			_commands.insert(std::make_pair("player_move_right", std::make_shared<PlayerMoveRightCommand>(main_controller)));
			_commands.insert(std::make_pair("player_jump", std::make_shared<PlayerJumpCommand>(main_controller)));
			_commands.insert(std::make_pair("player_interact", std::make_shared<PlayerInteractCommand>(main_controller)));
			_commands.insert(std::make_pair("level_pause", std::make_shared<LevelPauseCommand>(main_controller)));
		}

		CommandFactory* CommandFactory::instance()
		{
			if (_instance.get() == nullptr) throw "CommandFactory is not initialized";
			return _instance.get();
		}

		void CommandFactory::init(const std::shared_ptr<Controllers::MainController> main_controller)
		{
			_instance.reset(new CommandFactory(main_controller));
		}

		const std::shared_ptr<Command> CommandFactory::get_command(const std::string& command_name) const
		{
			if (_commands.find(command_name) != _commands.end()) {
				return _commands.at(command_name);
			}
			return nullptr;
		}
	}
}