#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"

struct Mix_Chunk;

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
		* \class SoundFacade
		* \brief Class contains the methods to interact with SDL_Mixer for sound
		*/
		class SoundFacade : public Interfaces::IAudioFacade {
		private:
			/**
			* \brief The Mix_Music from SDL2 to be able to perform actions on the audio file
			*/
			std::unique_ptr<Mix_Chunk, void(*)(Mix_Chunk*)> _sound;

			/**
			* \brief The channel of the current audio file
			*/
			const int _channel;
		public:
			SoundFacade(const std::string& path, int channel);

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
			
			/**
			* \brief Checks if the audio file is playing
			*/
			bool is_playing() const;
		};
	}
}