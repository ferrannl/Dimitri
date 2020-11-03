#pragma once
#include <src\Controllers\AudioController.h>
#include <iostream>
#include <src\Helpers\BasePathHelper.h>

namespace Game {
	namespace Controllers {
		class AudioController {
		private:
			std::unique_ptr<Audio::Controllers::AudioController> _audio_controller;
		public:
			AudioController();
			void add_music(const std::string name, const std::string song_path);
			void add_sound(const std::string name, const std::string song_path);

			void play_audio(const std::string name);
			void pause_audio(const std::string name);
			void resume_audio(const std::string name);
			void stop_audio(const std::string name);
		};
	}
}
