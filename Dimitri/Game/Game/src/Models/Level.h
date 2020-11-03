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

namespace Game
{
	namespace Models
	{
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
			*	Player Object
			*/
			std::shared_ptr<Game::Models::IObject> _player;
			
			/**
			*	List of tiles in level
			*/
			std::vector<std::shared_ptr<Game::Models::IObject>> _tiles;
			
			/**
			*	List of interactables in level
			*/
			std::vector<std::shared_ptr<Game::Models::IInteractable>> _interactables;
			
			/**
			*	List of invisible borders in level
			*/
			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _borders;
			
			/**
			*	Level background
			*/
			std::shared_ptr<Graphics::Models::Texture> _background;
			
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

			/**
			*	Returns list of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;
			
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
			*	Calls physics simulation
			*/
			void simulate();
		};
	}

}