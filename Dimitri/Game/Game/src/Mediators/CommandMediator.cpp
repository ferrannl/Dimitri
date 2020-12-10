#include "CommandMediator.h"

namespace Game {
	namespace Mediators {
		std::unique_ptr<CommandMediator> CommandMediator::_instance{ nullptr };

		CommandMediator::CommandMediator(const std::shared_ptr<Controllers::MainController> main_controller) :
			_factory{ std::make_unique<Commands::CommandFactory>(main_controller) } { }

		CommandMediator* CommandMediator::instance()
		{
			if (_instance.get() == nullptr) throw "CommandMediator is not initialized";
			return _instance.get();
		}

		void CommandMediator::init(const std::shared_ptr<Controllers::MainController> main_controller)
		{
			_instance.reset(new CommandMediator(main_controller));
		}

		void CommandMediator::notify(const BaseComponent& sender, Events::InputEvent event)
		{
			if (sender.get_identifier() == "MainController") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_QUIT:
					_factory->get_command("exit_game")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_C:
					_factory->get_command("open_credits_view")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_H:
					_factory->get_command("open_help_view")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_ESC:
					_factory->get_command("open_home_view")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_F:
					_factory->get_command("toggle_view")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "LevelController") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("player_move_left")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
					_factory->get_command("player_move_right")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_UP:
					_factory->get_command("player_jump")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_E:
					_factory->get_command("player_interact")->execute();
					break;
				case Input::Enums::EventEnum::KEY_PRESS_P:
					_factory->get_command("pause_level")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "StartButton") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("load_level")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "ExitButton") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("exit_game")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "IncreaseGameSpeedButton") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("increase_game_speed")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "DecreaseGameSpeedButton") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("decrease_game_speed")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "HighscoreButton") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::KEY_PRESS_LEFT:
					_factory->get_command("load_highscore")->execute();
				}
			}

		}

		void CommandMediator::notify(const BaseComponent& sender, Enums::LevelStateEnum event)
		{
			if (sender.get_identifier() == "LevelController") {
				switch (event) {
				case Enums::LevelStateEnum::ACTIVE:
					_factory->get_command("open_level_view")->execute();
					break;
				case Enums::LevelStateEnum::WIN:
					_factory->get_command("open_win_level_view")->execute();
					break;
				case Enums::LevelStateEnum::GAME_OVER:
					_factory->get_command("open_game_over_level_view")->execute();
					break;
				case Enums::LevelStateEnum::PAUSED:
					_factory->get_command("open_pause_level_view")->execute();
					break;
				}
			}
		}
	}
}
