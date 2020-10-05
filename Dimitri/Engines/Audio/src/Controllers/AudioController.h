#pragma once
#include "../Models/Audio.h"
#include "../Handlers/MusicPlayer.h"
#include "../Handlers/SoundPlayer.h"
#include <vector>

namespace Controllers {
	class __declspec(dllexport) AudioController {
	private:
		std::vector<Models::Audio>* _sounds;
		std::vector<Models::Audio>* _music;

		Models::Audio get_sound_by_name(std::string* name);
		Models::Audio get_music_by_name(std::string* name);

		Handlers::SoundPlayer* _sound_player;
		Handlers::MusicPlayer* _music_player;
	public:
		void add_sound(std::string* name, const char* path);
		void add_music(std::string* name, const char* path);
		
		void play_sound(std::string* name);
		void play_music(std::string* name);

		void resume_sound(std::string* name);
		void resume_music(std::string* name);

		void pause_sound(std::string* name);
		void pause_music(std::string* name);

		void stop_sound(std::string* name);
		void stop_music(std::string* name);
	};
}