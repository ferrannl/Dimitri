#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"

namespace Models {
	class __declspec(dllexport) Audio {
	private:
		std::string* _name;
		Interfaces::IAudioFacade* _audio_facade;
	public:
		std::string* get_name();
		Audio(std::string* name, Interfaces::IAudioFacade* audio_facade);
		Interfaces::IAudioFacade* get_audio_facade();
	};
}