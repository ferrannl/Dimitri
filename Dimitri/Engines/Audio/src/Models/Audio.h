#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"
#include <memory>

namespace Models {
	class __declspec(dllexport) Audio {
	private:
		const std::string _name;
		const std::shared_ptr<Interfaces::IAudioFacade> _audio_facade;
	public:
		Audio(const std::string name, std::shared_ptr < Interfaces::IAudioFacade> audio_facade);

		std::string get_name() const;
		std::shared_ptr<Interfaces::IAudioFacade> get_audio_facade() const;
	};
}