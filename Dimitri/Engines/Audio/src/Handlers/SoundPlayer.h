#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "../Interfaces/IAudioPlayer.h"
#include "../Adapters/SoundAdapter.h"

namespace Handlers {
	class __declspec(dllexport) SoundPlayer : public Interfaces::IAudioPlayer {
	public:
		//SoundPlayer() { _audio_adapter = new Adapters::SoundAdapter(); }
	};

}