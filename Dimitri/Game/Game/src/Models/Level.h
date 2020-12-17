#pragma once
#include "../Controllers/AudioController.h"
#include "../Controllers/WindowController.h"
#include <memory>
#include <chrono>
#include <thread>
#include <src\Models\Texture.h>
#include "./Abstract/Object.h"
#include <src/Models/Sprite.h>
#include "../Enums/TypeEnum.h"
#include "./IObjects/Wall.h"
#include "./Updatables/Player.h"
#include "./Updatables/Enemy.h"
#include "../Controllers/PhysicsCollisionController.h"
#include "./Interactable/Switch.h"
#include "./Updatables/LightBeam.h"
#include "Lamp.h"
#include "./Abstract/Updatable.h"
#include "Button.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class Level
		* \brief Class contains the methods to interact with the Objects
		*/
		class Level {
		private:
			/**
			* \brief An instance of the AudioContoller to interact with audio engine
			*/
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;

			/**
			* \brief An instance of the PhysicsCollisionContoller to interact with physics collision engine
			*/
			std::shared_ptr<Game::Controllers::PhysicsCollisionController> _physics_collision_controller;

			/**
			* \brief A list of the Buttons
			*/
			std::vector<std::shared_ptr<Game::Models::Button>> _buttons;

			/**
			* \brief List of all the Shapes in the Level
			*/
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _shapes;

			/**
			* \brief Speed of the level
			*/
			float _speed;

			/**
			* \brief An instance of the Player Object
			*/
			std::shared_ptr<Game::Models::Player> _player;

			/**
			* \brief Instances of the Enemy Objects
			*/
			std::vector<std::shared_ptr<Game::Models::Object>> _tiles;

			/**
			* \brief List of the enemies
			*/
			std::vector<std::shared_ptr<Game::Models::Enemy>> _enemies;

			/**
			* \brief List of backgrounds in the Level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Sprite>> _backgrounds;

			/**
			* \brief List of updatables in the Level
			*/
			std::vector<std::shared_ptr<Models::Updatable>> _updatables;

			/**
			* \brief List of updatables in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::Interactable>> _interactables;

			/**
			* \brief The height of the Level
			*/
			float _height;

			/**
			* \brief The width of the Level
			*/
			float _width;

		public:
			Level(const std::shared_ptr<Controllers::AudioController> audio_controller, const std::shared_ptr<Controllers::WindowController> window_controller, const float width, const float height);

			/**
			* \brief Returns a list of buttons
			*/
			std::vector<std::shared_ptr<Game::Models::Button>> get_buttons();

			/**
			* 	\brief Returns the speed of the level		
			*/
			void set_speed(float speed);

			/**
			* 	\brief Returns the speed of the level
			*/
			float get_speed() const;

			/**
			* \brief Add music
			*/
			void add_music(std::string audio_name, std::string path, int volume = 50);

			/**
			* \brief Add sound
			*/
			void add_sound(std::string audio_name, std::string path, int volume = 50);

			/**
			* \brief Play music
			*/
			void play_music(std::string audio_name);

			/**
			* \brief Stop music
			*/
			void stop_music(std::string audio_name);

			/**
			* \brief Pause music
			*/
			void pause_music(std::string audio_name);

			/**
			* \brief Resume music
			*/
			void resume_music(std::string audio_name);

			void volume_control(std::string audio_name, int volume);

			/**
			* \brief Initializes objects
			*/
			void load_objects();

			/**
			* \brief Add the Shapes of the Objects in _shapes, _player, _interactables, _updatables and _tiles in the physics collision engine
			*/
			void add_shapes();

			/**
			* \brief Returns list of all Textures in the Level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			* \brief Returns the Player
			*/
			std::vector<std::shared_ptr<Game::Models::Enemy>> get_enemies() const;

			/**
			*	\brief Returns the tiles
			*/
			std::vector<std::shared_ptr<Game::Models::Object>> get_tiles() const;		

			/**
			* \brief Returns the interactables
			*/
			std::vector<std::shared_ptr<Game::Models::Interactable>> get_interactables() const;

			/**
			* \brief Returns the updatables
			*/
			std::vector<std::shared_ptr<Game::Models::Updatable>> get_updatables() const;

			/**
			* \brief Returns the PhysicsCollisionController
			*/
			std::shared_ptr<Game::Controllers::PhysicsCollisionController> get_physics_collision_controller() const;

			/**
			* \brief Adds tile to the _tiles list
			*/
			void add_tile(std::shared_ptr<Game::Models::Object> tile);

			/**
			* \brief Adds player to _player
			*/
			void add_player(std::shared_ptr<Game::Models::Player> tile);

			/**
			* \brief Adds interactable to the _interactables list
			*/
			void add_interactable(std::shared_ptr<Game::Models::Interactable> tile);

			/**
			* \brief Adds updatables to the _updatables list
			*/
			void add_updatable(std::shared_ptr<Game::Models::Updatable> tile);

			/**
			* \brief Adds background to the _backgrounds list
			*/
			void add_background(std::shared_ptr<Graphics::Models::Sprite> tile);

			/**
			* \brief Adds an enemy to the level
			*/
			void add_enemy(std::shared_ptr<Game::Models::Enemy> tile);

			/**
			* \brief Adds shape to the _shapes list
			*/
			void add_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape);

			/**
			* \brief Calls physics simulation
			*/
			void simulate();

			/**
			* \brief Returns the height of the Level
			*/
			float get_height() const;

			/**
			* \brief Returns the width of the Level
			*/
			float get_width() const;

			/**
			* \brief Returns the player
			*/
			std::shared_ptr<Game::Models::Player> get_player()const;
		};
	}

}
