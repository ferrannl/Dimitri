#pragma once
#include "../Models/Audio.h"
#include "../Facades/SoundFacade.h"
#include "../Facades/MusicFacade.h"
#include <vector>
#include <memory>

namespace Controllers {
	class __declspec(dllexport) AudioController {
	private:
		std::unique_ptr<std::vector<std::shared_ptr<Models::Audio>>> _audios;
		std::shared_ptr<Models::Audio> get_audio_by_name(const std::string name) const;
		int _channel_counter;
	public:
		AudioController();

		void add_sound(const std::string name, const char* path);
		void add_music(const std::string name, const char* path);
		
		void play_audio(const std::string name) const;
		void resume_audio(const std::string name) const;
		void pause_audio(const std::string name) const;
		void stop_audio(const std::string name) const;

		// forbid copying and moving
		AudioController(const AudioController& audio_controller) = delete;
		AudioController& operator=(const AudioController& audio_controller) = delete;
		AudioController(AudioController&& audio_controller) = delete;
		AudioController& operator=(AudioController&& audio_controller) = delete;

		~AudioController();
	};
}