#pragma once
#include "../../Engines/Audio/src/Controllers/AudioController.h"
#include <memory>
class AudioDemo {
private:
	Controllers::AudioController* _audio_controller;
public:
	AudioDemo() {
		_audio_controller = new Controllers::AudioController();
	}
	void play_music();
	void play_sound();
};