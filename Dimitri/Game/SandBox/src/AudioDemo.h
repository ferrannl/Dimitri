#pragma once
#include "../../Engines/Audio/src/Controllers/AudioController.h"
#include "../../Utility/src/Helpers/BasePathHelper.h"
#include <memory>
#include <chrono>
#include <thread>
#include <src\Controllers\AudioController.h>

using namespace std::this_thread;
using namespace std::chrono_literals;

class AudioDemo {
private:
	std::unique_ptr<Audio::Controllers::AudioController> _audio_controller;
public:
	AudioDemo();
	void play_music() const;
	void play_sound() const;
};