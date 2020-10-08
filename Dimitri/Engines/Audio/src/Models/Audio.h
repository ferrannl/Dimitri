#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"
#include <memory>

namespace Models {
	class __declspec(dllexport) Audio {
	private:
		std::shared_ptr<std::string> _name;
		std::shared_ptr<Interfaces::IAudioFacade> _audio_facade;
	public:
		Audio(std::shared_ptr <std::string> name, std::shared_ptr < Interfaces::IAudioFacade> audio_facade);

		std::shared_ptr<std::string> get_name();
		std::shared_ptr<Interfaces::IAudioFacade> get_audio_facade();

		// forbid copying and moving
		Audio(const Audio& audio) = delete;
		Audio& operator=(const Audio& audio) = delete;
		Audio(Audio&& audio) = delete;
		Audio& operator=(Audio&& audio) = delete;

		~Audio();
	};
}