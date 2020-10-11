#pragma once
#include "../../Engines/Audio/src/Controllers/AudioController.h"
#include <filesystem>

class AudioDemo {
private:
	Controllers::AudioController _audio_controller;
public:
	AudioDemo() {
		_audio_controller = {};
	}
	void play_music();
	void play_sound();
};