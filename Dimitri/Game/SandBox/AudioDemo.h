#pragma once
#include "../../Engines/Audio/src/Controllers/AudioController.h"
#include <memory>
class AudioDemo {
private:
	std::unique_ptr<Controllers::AudioController> _audio_controller;
public:
	AudioDemo() {
		_audio_controller = std::make_unique<Controllers::AudioController>();
	}
	void play_music();
	void play_sound();
};