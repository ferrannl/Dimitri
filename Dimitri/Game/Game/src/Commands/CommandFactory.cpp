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
#include "PauseLevelCommand.h"
#include "OpenWinLevelViewCommand.h"
#include "OpenPauseLevelViewCommand.h"
#include "OpenGameOverLevelViewCommand.h"
#include "OpenHighscoreViewCommand.h"
#include "OpenLevelViewCommand.h"
#include "IncreaseGameSpeedCommand.h"
#include "DecreaseGameSpeedCommand.h"

namespace Game {
	namespace Commands {

		CommandFactory::CommandFactory(const std::shared_ptr<Controllers::MainController> main_controller) {
			_commands.insert(std::make_pair("exit_game", std::make_unique<ExitGameCommand>(main_controller)));
			_commands.insert(std::make_pair("load_level", std::make_unique<LoadLevelCommand>(main_controller)));
			_commands.insert(std::make_pair("open_credits_view", std::make_unique<OpenCreditsViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_help_view", std::make_unique<OpenHelpViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_home_view", std::make_unique<OpenHomeViewCommand>(main_controller)));
			_commands.insert(std::make_pair("toggle_view", std::make_unique<ToggleFpsViewCommand>(main_controller)));
			_commands.insert(std::make_pair("player_move_left", std::make_unique<PlayerMoveLeftCommand>(main_controller)));
			_commands.insert(std::make_pair("player_move_right", std::make_unique<PlayerMoveRightCommand>(main_controller)));
			_commands.insert(std::make_pair("player_jump", std::make_unique<PlayerJumpCommand>(main_controller)));
			_commands.insert(std::make_pair("player_interact", std::make_unique<PlayerInteractCommand>(main_controller)));
			_commands.insert(std::make_pair("pause_level", std::make_unique<PauseLevelCommand>(main_controller)));
			_commands.insert(std::make_pair("open_win_level_view", std::make_unique<OpenWinLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_pause_level_view", std::make_unique<OpenPauseLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_game_over_level_view", std::make_unique<OpenGameOverLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair("open_level_view", std::make_unique<OpenLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair("increase_game_speed", std::make_unique<IncreaseGameSpeedCommand>(main_controller)));
			_commands.insert(std::make_pair("decrease_game_speed", std::make_unique<DecreaseGameSpeedCommand>(main_controller)));
			_commands.insert(std::make_pair("load_highscore", std::make_unique<OpenHighscoreViewCommand>(main_controller)));
		}

		Command* CommandFactory::get_command(const std::string& command_name) const
		{
			if (_commands.find(command_name) != _commands.end()) {
				return _commands.at(command_name).get();
			}
			return nullptr;
		}
	}
}
