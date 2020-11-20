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
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Contains all code necessary for the level object
		*/
		class Level
		{
		private:
			/**
			*	Audio Contoller to interact with audio engine
			*/
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;
			
			/**
			*	PhysicsCollision Contoller to interact with Physics Collision engine
			*/
			std::shared_ptr<Game::Controllers::PhysicsCollisionController> _physics_collision_controller;

			/**
			*	List of all the shapes in level
			*/
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _shapes;

			/**
			*	Player Object
			*/
			std::shared_ptr<Game::Models::IObject> _player;
			
			/**
			*	List of tiles in level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _tiles;

			/**
			*	List of lights in level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _lights;
			
			/**
			*	List of players in level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _players;

			/**
			*	List of players in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Sprite>> _backgrounds;

			/**
			*	List of interactables in level
			*/
			std::vector<std::shared_ptr<Game::Models::IInteractable>> _interactables;

			/**
			*	Size of the level
			*/
			int _height;
			int _width;
			
		public:
			Level();
			
			/**
			*	Add music
			*/
			void add_music(std::string audio_name, std::string path);
			/**
			*	Add sound
			*/
			void add_sound(std::string audio_name, std::string path);
			/**
			*	Play music
			*/
			void play_music(std::string audio_name);
			/**
			*	Stop music
			*/
			void stop_music(std::string audio_name);
			/**
			*	Pause music
			*/
			void pause_music(std::string audio_name);
			/**
			*	Resume music
			*/
			void resume_music(std::string audio_name);

			/**
			*	Initializes objects
			*/
			void load_objects();

			void add_shapes();

			/**
			*	Returns list of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;

			/**
			*	Returns list of all lights in level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> get_lights() const;
			
			/**
			*	Returns player
			*/
			std::shared_ptr<Game::Models::IObject> get_player() const;
			
			/**
			*	Returns interactables
			*/
			std::vector<std::shared_ptr<Game::Models::IInteractable>> get_interactables() const;
			
			/**
			*	Returns physics collision controller
			*/
			std::shared_ptr<Game::Controllers::PhysicsCollisionController> get_physics_collision_controller() const;

			/**
			*	Returns physics collision controller
			*/
			void add_object(std::shared_ptr<Game::Models::IObject> tile);

			/**
			*	Returns physics collision controller
			*/
			void add_player(std::shared_ptr<Game::Models::IObject> tile);

			/**
			*	Returns physics collision controller
			*/
			void add_interactable(std::shared_ptr<Game::Models::IInteractable> tile);

			void add_background(std::shared_ptr<Graphics::Models::Sprite> tile);

			/**
			*	Calls physics simulation
			*/
			void simulate();

			/**
			* Getters for level size
			*/
			int get_level_height() const;

			int get_level_width() const;
		};
	}

}