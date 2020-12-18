#include "CommandMediator.h"
#include "../Controllers/LevelController.h"

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
					_factory->get_command(Enums::CommandEnum::EXIT_GAME)->execute(-1);
					break;
				case Input::Enums::EventEnum::KEY_PRESS_F:
					_factory->get_command(Enums::CommandEnum::TOGGLE_FPS_VIEW)->execute(-1);
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
							{Enums::ButtonEnum::PAUSED_START, Enums::CommandEnum::PAUSE_LEVEL},
							{Enums::ButtonEnum::PAUSED_HOME, Enums::CommandEnum::OPEN_HOME_VIEW},
							});
						break;
					/*case Input::Enums::EventEnum::KEY_PRESS_P:
						_factory->get_command(Enums::CommandEnum::PAUSE_LEVEL)->execute();
						break;*/
					}
					break;
				case Enums::LevelStateEnum::GAME_OVER:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, {
							{Enums::ButtonEnum::GAMEOVER_START, Enums::CommandEnum::TRY_AGAIN_GAME},
							{Enums::ButtonEnum::GAMEOVER_HOME, Enums::CommandEnum::OPEN_HOME_VIEW}
							});
						break;
					}
					break;
				case Enums::LevelStateEnum::WIN:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, { {Enums::ButtonEnum::WIN_HOME, Enums::CommandEnum::OPEN_HOME_VIEW} });
						break;
					}
					break;
				case Enums::LevelStateEnum::TRANSITION:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::KEY_PRESS_SPACE:
						_factory->get_command(Enums::CommandEnum::CLEAR_VIEWS)->execute(-1);
						break;
					}
					break;

				default:
					switch (event.event_enum) {
					case Input::Enums::EventEnum::KEY_PRESS_LEFT:
						_factory->get_command(Enums::CommandEnum::PLAYER_MOVE_LEFT)->execute(-1);
						break;
					case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
						_factory->get_command(Enums::CommandEnum::PLAYER_MOVE_RIGHT)->execute(-1);
						break;
					case Input::Enums::EventEnum::KEY_PRESS_UP:
						_factory->get_command(Enums::CommandEnum::PLAYER_JUMP)->execute(-1);
						break;
					case Input::Enums::EventEnum::KEY_PRESS_E:
						_factory->get_command(Enums::CommandEnum::PLAYER_INTERACT)->execute(-1);
						break;
					case Input::Enums::EventEnum::KEY_PRESS_P:
						_factory->get_command(Enums::CommandEnum::PAUSE_LEVEL)->execute(-1);
						break;
					case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
						notify_buttons(sender, event, {
							{Enums::ButtonEnum::INCREASE_GAMEPLAY_SPEED, Enums::CommandEnum::INCREASE_GAMESPEED},
							{Enums::ButtonEnum::DECREASE_GAMEPLAY_SPEED, Enums::CommandEnum::DECREASE_GAMESPEED}
							});
					}
					break;
				}
			}
			else if (sender.get_identifier() == "HomeController") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, {
						{Enums::ButtonEnum::HELP, Enums::CommandEnum::OPEN_HELP_VIEW},
						{Enums::ButtonEnum::CREDITS, Enums::CommandEnum::OPEN_CREDITS_VIEW},
						{Enums::ButtonEnum::EXIT, Enums::CommandEnum::EXIT_GAME},
						{Enums::ButtonEnum::HIGHSCORE, Enums::CommandEnum::LOAD_HIGHSCORE},
						{Enums::ButtonEnum::SAVE_GAMES, Enums::CommandEnum::OPEN_SAVE_GAME_VIEW},
						{Enums::ButtonEnum::CHEATS, Enums::CommandEnum::OPEN_CHEATS_VIEW},
						});
					break;
				}
			}
			else if (sender.get_identifier() == "CreditsController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, { {Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW} });
					break;
				}
			}
			else if (sender.get_identifier() == "HelpController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, { {Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW} });
					break;
				}
			}
			else if (sender.get_identifier() == "HighscoreManager")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, { {Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW} });
					break;
				}
			}
			else if (sender.get_identifier() == "CheatsController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, {
						{Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW},
						{Enums::ButtonEnum::CHEATS_CHECKBOX_INFINITE, Enums::CommandEnum::CHEATS_INFINITE},
						{Enums::ButtonEnum::CHEATS_CHECKBOX_INVINCIBLE, Enums::CommandEnum::CHEATS_INVINCIBLE},
						});
					break;
				}
			}
			else if (sender.get_identifier() == "SaveGameController")
			{
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, {
						{Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW},
						{Enums::ButtonEnum::NEW1, Enums::CommandEnum::OPEN_LEVEL_SELECTOR_VIEW} });
					break;
				}
			}
			else if (sender.get_identifier() == "LevelSelectorController") {
				switch (event.event_enum) {
				case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:
					notify_buttons(sender, event, {
						{Enums::ButtonEnum::HOME, Enums::CommandEnum::OPEN_HOME_VIEW},
						{Enums::ButtonEnum::START_TUTORIAL, Enums::CommandEnum::LOAD_LEVEL},
						{Enums::ButtonEnum::START_LEVEL_1, Enums::CommandEnum::LOAD_LEVEL},
						{Enums::ButtonEnum::START_LEVEL_2, Enums::CommandEnum::LOAD_LEVEL},
						{Enums::ButtonEnum::START_LEVEL_3, Enums::CommandEnum::LOAD_LEVEL},
						});
				}
			}
		}

		void CommandMediator::notify(const BaseComponent& sender, Enums::LevelStateEnum event)
		{
			if (sender.get_identifier() == "LevelController") {
				switch (event) {
				case Enums::LevelStateEnum::TRANSITION:
					_factory->get_command(Enums::CommandEnum::OPEN_LEVEL_TRANSITION_VIEW)->execute(-1);
					break;
				case Enums::LevelStateEnum::ACTIVE:
					_factory->get_command(Enums::CommandEnum::OPEN_LEVEL_VIEW)->execute(-1);
					break;
				case Enums::LevelStateEnum::WIN:
					_factory->get_command(Enums::CommandEnum::OPEN_WIN_LEVEL_VIEW)->execute(-1);
					break;
				case Enums::LevelStateEnum::GAME_OVER:
					_factory->get_command(Enums::CommandEnum::OPEN_GAME_OVER_LEVEL_VIEW)->execute(-1);
					break;
				case Enums::LevelStateEnum::PAUSED:
					_factory->get_command(Enums::CommandEnum::OPEN_PAUSE_LEVEL_VIEW)->execute(-1);
					break;
				}
			}
		}

		void CommandMediator::notify_buttons(const BaseComponent& sender, Events::InputEvent event, const std::map<Enums::ButtonEnum, Enums::CommandEnum>& button_command)
		{
			for (auto& b : sender.get_buttons()) {

				if (b->is_clicked(event)) {
					for (auto& c : button_command) {
						if (b->get_identifier() == c.first) {				
							_factory->get_command(c.second)->execute(b->get_param());
						}
					}
				}
			}
		}
	}
}
