#pragma once
#include "../Controllers/AudioController.h"
#include <memory>
#include <chrono>
#include <thread>
#include <src\Models\Texture.h>
#include "../Models/IObject.h"
#include <src/Models/Sprite.h>
#include "Wall.h"
#include "Player.h"
#include "../Controllers/PhysicsCollisionController.h"
#include "Switch.h"
#include "LightBeam.h"
#include "Lamp.h"

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
		* \brief Class contains the methods to interact with the IObjects
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
			* \brief List of all the Shapes in the Level
			*/
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _shapes;

			/**
			* \brief An instance of the Player Object
			*/
			std::shared_ptr<Game::Models::Player> _player;

			/**
			* \brief List of tiles in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _tiles;

			/**
			* \brief List of light in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _lights;

			/**
			* \brief List of players in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _players;

			/**
			* \brief List of interactables in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::IInteractable>> _interactables;

			/**
			* \brief Texture of the background
			*/
			std::shared_ptr<Graphics::Models::Texture> _background;

			/**
			* \brief The height of the Level
			*/
			int _height;

			/**
			* \brief The width of the Level
			*/
			int _width;

		public:
			Level();

			/**
			* \brief Add music
			*/
			void add_music(std::string audio_name, std::string path);

			/**
			* \brief Add sound
			*/
			void add_sound(std::string audio_name, std::string path);

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

			/**
			* \brief Initializes objects
			*/
			void load_objects();

			/**
			* \brief Add the Shapes of the IObjects in _shapes, _players, _lights, _tiles and _interactables in the physics collision engine
			*/
			void add_shapes();

			/**
			* \brief Returns list of all Textures in the Level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			* \brief Returns list of all Lights in the Level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> get_lights() const;

			/**
			* \brief Returns the Player
			*/
			std::shared_ptr<Game::Models::Player> get_player() const;
			
			/**
			*	\brief Returns the tiles
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> get_tiles() const;		

			/**
			* \brief Returns the interactables
			*/
			std::vector<std::shared_ptr<Game::Models::IInteractable>> get_interactables() const;

			/**
			* \brief Returns the PhysicsCollisionController
			*/
			std::shared_ptr<Game::Controllers::PhysicsCollisionController> get_physics_collision_controller() const;

			/**
			* \brief Calls simulate in the PhysicsCollisionController
			*/
			void simulate();

			/**
			* \brief Returns the height of the Level
			*/
			int get_level_height() const;

			/**
			* \brief Returns the width of the Level
			*/
			int get_level_width() const;
		};
	}

}