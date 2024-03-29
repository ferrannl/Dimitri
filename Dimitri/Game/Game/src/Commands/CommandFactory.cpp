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
#include "OpenSaveGameViewCommand.h"
#include "OpenCheatsViewCommand.h"
#include "SetCheatInfiniteCommand.h"
#include "SetCheatInvincibleCommand.h"
#include "OpenLevelTransitionViewCommand.h"
#include "ClearViewsCommand.h"
#include "IncreaseGameSpeedCommand.h"
#include "DecreaseGameSpeedCommand.h"
#include "OpenLevelSelectorViewCommand.h"
#include "TryAgainCommand.h"

namespace Game {
	namespace Commands {

		CommandFactory::CommandFactory(const std::shared_ptr<Controllers::MainController> main_controller) {
			_commands.insert(std::make_pair(Enums::CommandEnum::EXIT_GAME, std::make_unique<ExitGameCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::LOAD_LEVEL, std::make_unique<LoadLevelCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_CREDITS_VIEW, std::make_unique<OpenCreditsViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_HELP_VIEW, std::make_unique<OpenHelpViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_HOME_VIEW, std::make_unique<OpenHomeViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::TOGGLE_FPS_VIEW, std::make_unique<ToggleFpsViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::PLAYER_MOVE_LEFT, std::make_unique<PlayerMoveLeftCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::PLAYER_MOVE_RIGHT, std::make_unique<PlayerMoveRightCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::PLAYER_JUMP, std::make_unique<PlayerJumpCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::PLAYER_INTERACT, std::make_unique<PlayerInteractCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::PAUSE_LEVEL, std::make_unique<PauseLevelCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_WIN_LEVEL_VIEW, std::make_unique<OpenWinLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_PAUSE_LEVEL_VIEW, std::make_unique<OpenPauseLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_GAME_OVER_LEVEL_VIEW, std::make_unique<OpenGameOverLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_LEVEL_VIEW, std::make_unique<OpenLevelViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::LOAD_HIGHSCORE, std::make_unique<OpenHighscoreViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_SAVE_GAME_VIEW, std::make_unique<OpenSaveGameViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_CHEATS_VIEW, std::make_unique<OpenCheatsViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::CHEATS_INFINITE, std::make_unique<SetCheatInfiniteCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::CHEATS_INVINCIBLE, std::make_unique<SetCheatInvincibleCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_LEVEL_TRANSITION_VIEW, std::make_unique<OpenLevelTransitionViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::CLEAR_VIEWS, std::make_unique<ClearViewsCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::INCREASE_GAMESPEED, std::make_unique<IncreaseGameSpeedCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::DECREASE_GAMESPEED, std::make_unique<DecreaseGameSpeedCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::OPEN_LEVEL_SELECTOR_VIEW, std::make_unique<OpenLevelSelectorViewCommand>(main_controller)));
			_commands.insert(std::make_pair(Enums::CommandEnum::TRY_AGAIN_GAME, std::make_unique<TryAgainCommand>(main_controller)));
		}

		const std::unique_ptr<Command>& CommandFactory::get_command(Enums::CommandEnum command_name) const
		{
			if (_commands.find(command_name) != _commands.end()) {
				return _commands.at(command_name);
			}
			return nullptr;
		}
	}
}
