#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif

/**
* \namespace Audio
* \brief Namespace for the audio engine
*/
namespace Audio {
	/**
	* \namespace Audio::Facades
	* \brief Namespace for the facades in the audio engine
	*/
	namespace Facades {
		/**
		* \class MusicFacade
		* \brief Class contains the methods to interact with SDL_Mixer for music
		*/
		class AUDIO_API MusicFacade : public Interfaces::IAudioFacade {
		private:
			/**
			* \brief The Mix_Music from SDL2 to be able to perform actions on the audio file
			*/
			std::unique_ptr<Mix_Music, decltype (&Mix_FreeMusic)> _music;
		public:
			MusicFacade(const std::string path);

			/**
			* \brief Plays the audio file using SDL_Mixer
			*/
			void play() const;

			/**
			* \brief Resumes the audio file using SDL_Mixer
			*/
			void resume() const;

			/**
			* \brief Pauses the audio file using SDL_Mixer
			*/
			void pause() const;

			/**
			* \brief Stops the audio file using SDL_Mixer
			*/
			void stop() const;
		};
	}
}