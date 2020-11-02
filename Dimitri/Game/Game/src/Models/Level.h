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

namespace Game
{
	namespace Models
	{
		class Level
		{
		private:
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;

			std::shared_ptr<Game::Models::IObject> _player;
			std::vector<std::shared_ptr<Game::Models::IObject>> _tiles;
			std::shared_ptr<Graphics::Models::Texture> _background;
		public:
			Level();
			void add_music(std::string audio_name, std::string path);
			void add_sound(std::string audio_name, std::string path);
			void play_music(std::string audio_name);
			void stop_music(std::string audio_name);
			void pause_music(std::string audio_name);
			void resume_music(std::string audio_name);

			/**
			*	Initializes objects
			*/
			void load_objects();

			/**
			*	Returns list of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures();
			
			/**
			*	Returns player
			*/
			std::shared_ptr<Game::Models::IObject> get_player();
		};
	}

}