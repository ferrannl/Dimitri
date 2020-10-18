#pragma once
#include <string>
#include <memory>
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Exceptions/AudioExceptions.h"
#include <iostream>
namespace Audio {
	namespace Interfaces {
		class __declspec(dllexport) IAudioFacade {
		protected:
			const std::string _path;
		public:
			IAudioFacade(const std::string path);
			virtual void play() const = 0;
			virtual void resume() const = 0;
			virtual void pause() const = 0;
			virtual void stop() const = 0;
		};
	}
}