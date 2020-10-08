#pragma once
#include "../Models/Audio.h"
#include "../Facades/SoundFacade.h"
#include "../Facades/MusicFacade.h"
#include <vector>

namespace Controllers {
	class __declspec(dllexport) AudioController {
	private:
		std::vector<Models::Audio*>* _audios;
		Models::Audio* get_audio_by_name(std::string* name);
		int _channel_counter;
	public:
		AudioController() {
			_audios = new std::vector<Models::Audio*>();
			_channel_counter = 0;
		}

		void add_sound(std::string* name, const char* path);
		void add_music(std::string* name, const char* path);
		
		void play_audio(std::string* name);
		void resume_audio(std::string* name);
		void pause_audio(std::string* name);
		void stop_audio(std::string* name);
	};
}