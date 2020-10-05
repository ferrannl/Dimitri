#pragma once
#include <stdio.h>
#include <string>
#include "../Interfaces/IAudioPlayer.h"
#include "../Adapters/MusicAdapter.h"

namespace Handlers {
	class __declspec(dllexport) MusicPlayer: public Interfaces::IAudioPlayer{
	public:
		//MusicPlayer() { _audio_adapter = new Adapters::MusicAdapter(); }
	};

}