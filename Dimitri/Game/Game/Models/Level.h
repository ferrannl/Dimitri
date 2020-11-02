#pragma once
#include "../Controllers/AudioController.h"
#include <memory>
#include <chrono>
#include <thread>
namespace Game
{
	namespace Models
	{
		class Level
		{
		private:
			std::shared_ptr<Game::Controllers::AudioController> _audio_controller;
		public:
			Level();
			void add_music_for_level(std::string audio_name, std::string path);
			void add_sound_for_level(std::string audio_name, std::string path);
			void play_music_for_level(std::string audio_name);
			void stop_music_for_level(std::string audio_name);
			void pause_music_for_level(std::string audio_name);
			void resume_music_for_level(std::string audio_name);

		};
	}

}