#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
namespace Handlers {
	class __declspec(dllexport) SoundPlayer {
	public:
		void init();
		void play_music();
		void play_sound();
		void close();
	};

}