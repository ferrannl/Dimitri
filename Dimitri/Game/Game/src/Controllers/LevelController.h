#pragma once
#include "../Models/Level.h"
#include "../Events/InputEvent.h"
#include "../Controllers/WindowController.h"
#include "../Controllers/AudioController.h"
#include "../Mediators/BaseComponent.h"
#include <src\Interfaces\IObservable.h>
#include <src\Models\Texture.h>
#include "../Models/Level.h"
#include "../Events/InputEvent.h"
#include "../Enums/LevelStateEnum.h"
#include <chrono>
#include <thread>
#include <any>
#include "../Models/Settings/CheatsSettings.h"
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		* \class LevelController
		* \brief Class LevelController contains the methods to interact with the Level
		*/
		class LevelController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Mediators::BaseComponent {
		private:
			std::vector<std::pair<std::string, Enums::ButtonEnum>> _button_map;
			/**
			* \brief An Instance of the current Level
			*/
			std::shared_ptr<Game::Models::Level> _level;

			/**
			* \brief An instance of the thread
			*/
			std::thread _transition_thread;

			/**
			* \brief An instance of the thread
			*/
			std::thread _simulation_thread;

			/**
			* \brief An instance of the thread
			*/
			std::thread _objects_thread;

			/**
			* \brief Keeps track of simulation thread state
			*/
			Enums::LevelStateEnum _state;

			/**
			* \brief An Instance of the WindowController
			*/
			std::shared_ptr<Controllers::WindowController> _window_controller;

			/**
			* \brief An Instance of the AudioController
			*/
			std::shared_ptr<Controllers::AudioController> _audio_controller;

			/**
			* \brief A list of the buttons per Level State
			*/
			std::vector<std::pair<Enums::LevelStateEnum, std::unique_ptr<Game::Models::Button>>> _buttons;

			/**
			* \brief cheat settings
			*/
			std::shared_ptr<Game::Models::CheatsSettings> _settings;
		public:
			LevelController(const std::shared_ptr<Controllers::WindowController> window_controller, const std::shared_ptr<Controllers::AudioController> audio_controller);

			/**
			* \brief Loads the buttons for a level
			*/
			void load_buttons();

			/**
			* \brief Returns a list of all Textures in the Level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures(Enums::LevelStateEnum state) const;

			/**
			* \brief Sets the speeds of a level
			*/
			void set_speed(float speed);

			/**
			* \brief Returns the speeds of a level
			*/
			float get_speed() const;

			/**
			* \brief Sets up the level
			*/
			void setup_level(const std::string& level);

			/**
			* \brief Receives updates from InputController
			*/
			void update(const Game::Events::InputEvent& object);

			/**
			* \brief Returns the Level
			*/
			std::shared_ptr<Game::Models::Level> get_level() const;

			/**
			* \brief Loads the secret audio
			*/
			void play_secret();

			/**
			* \brief Starts simulation
			*/
			void start();

			/**
			* \brief Stops simulation
			*/
			void stop();

			/**
			* \brief Polls events in the transition state
			*/
			void run_transition();

			/**
			* \brief Simulates the Level
			*/
			void simulate();

			/**
			* \brief Clears the level
			*/
			void clear_level();

			/**
			* \brief Set the level state and stops/starts the thread
			*/
			void set_state(Enums::LevelStateEnum state);

			/**
			* \brief Returns the state of the Level
			*/
			Enums::LevelStateEnum get_state() const;

			/**
			* \brief Simulates the objects
			*/
			void simulate_objects();

			/**
			* \brief Returns the buttons
			*/
			std::vector<Game::Models::Button*> get_buttons() const override;

			/**
			* \brief Toggles a light on or off
			*/
			void toggle_light(const std::tuple<int, int>& pos);

			/**
			* \brief Updates the highscore
			*/
			void update_highscore();

			/**
			* \brief Updates cheat settings
			*/
			void update_cheats(std::shared_ptr<Game::Models::CheatsSettings> _settings);

			/**
			* \brief Updates cheat settings
			*/
			std::shared_ptr<Game::Models::CheatsSettings> get_cheats_settings();
		};
	}
}
