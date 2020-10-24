#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"
#include <memory>

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif

namespace Models {
	class AUDIO_API Audio {
	private:
		const std::string _name;
		const std::shared_ptr<Interfaces::IAudioFacade> _audio_facade;
	public:
		Audio(const std::string name, std::shared_ptr < Interfaces::IAudioFacade> audio_facade);

		std::string get_name() const;
		std::shared_ptr<Interfaces::IAudioFacade> get_audio_facade() const;
	};
}