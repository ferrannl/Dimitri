#pragma once
#include "../../Engines/Audio/src/Controllers/AudioController.h"

class AudioDemo {
private:
	std::unique_ptr<Controllers::AudioController> _audio_controller;
public:
	AudioDemo();
	void play_music();
	void play_sound();
};