#pragma once
#include "../Models/Audio.h"
#include "../Facades/SoundFacade.h"
#include "../Facades/MusicFacade.h"
#include "../Exceptions/AudioExceptions.h"
#include <iostream>
#include <vector>
#include <memory>

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif

namespace Controllers {
	class AUDIO_API AudioController {
	private:
		std::unique_ptr<std::vector<std::shared_ptr<Models::Audio>>> _audios;
		std::shared_ptr<Models::Audio> get_audio_by_name(const std::string name) const;
		int _channel_counter;

		bool name_exists(const std::string name);
	public:
		AudioController();

		void add_sound(const std::string name, const std::string path);
		void add_music(const std::string name, const std::string path);

		void play_audio(const std::string name) const;
		void resume_audio(const std::string name) const;
		void pause_audio(const std::string name) const;
		void stop_audio(const std::string name) const;
	};
}