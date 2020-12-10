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
				case Input::Enums::EventEnum::KEY_PRESS_F:
					_factory->get_command("toggle_view")->execute();
					break;
				}
			}
			else if (sender.get_identifier() == "LevelController") {
				BaseComponent& not_const = const_cast<BaseComponent&>(sender);
				auto& ctrl = dynamic_cast<Controllers::LevelController&>(not_const);
				switch (ctrl.get_state()) {
				case Enums::LevelStateEnum::PAUSED:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, {
							{Enums::ButtonEnum::PAUSED_START, "pause_level"},
							{Enums::ButtonEnum::PAUSED_HOME, "open_home_view"}
							});
						break;
					case Input::Enums::EventEnum::KEY_PRESS_P:
						_factory->get_command("pause_level")->execute();
						break;
					}
					break;
				case Enums::LevelStateEnum::GAME_OVER:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, {
							{Enums::ButtonEnum::GAMEOVER_START, "load_level"},
							{Enums::ButtonEnum::GAMEOVER_HOME, "open_home_view"}
							});
						break;
					}
					break;
				case Enums::LevelStateEnum::WIN:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, { {Enums::ButtonEnum::WIN_HOME, "open_home_view"} });
						break;
					}
					break;
				default:
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
					break;
				}
			}
			else if (sender.get_identifier() == "HomeController") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, {
						{Enums::ButtonEnum::START, "load_level"},
						{Enums::ButtonEnum::HELP, "open_help_view"},
						{Enums::ButtonEnum::CREDITS, "open_credits_view"},
						{Enums::ButtonEnum::EXIT, "exit_game"},
						});
					break;
				}
			}
			else if (sender.get_identifier() == "CreditsController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, { {Enums::ButtonEnum::HOME, "open_home_view"} });
					break;
				}
			}
			else if (sender.get_identifier() == "HelpController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, { {Enums::ButtonEnum::HOME, "open_home_view"} });
					break;
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

		void CommandMediator::notify_buttons(const BaseComponent& sender, Events::InputEvent event, const std::map<Enums::ButtonEnum, std::string>& button_command)
		{
			for (auto& b : sender.get_buttons()) {
				if (b->is_clicked(event)) {
					for (auto& c : button_command) {
						if (b->get_identifier() == c.first) {
							_factory->get_command(c.second)->execute();
						}
					}
				}
			}
		}
	}
}