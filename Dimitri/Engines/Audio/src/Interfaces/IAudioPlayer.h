#pragma once
#include <string>
#include "../Models/Audio.h"
#include "IAudioAdapter.h"
namespace Interfaces {
	class __declspec(dllexport) IAudioPlayer {
	protected:
		Interfaces::IAudioAdapter* _audio_adapter;
	public:
		void play(Models::Audio* audio);
		void resume(Models::Audio* audio);
		void pause(Models::Audio* audio);
		void stop(Models::Audio* audio);
	};
}