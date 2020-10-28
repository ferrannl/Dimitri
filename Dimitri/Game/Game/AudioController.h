#pragma once
#include <iostream>
#include "../../Engines/Audio/src/Controllers/AudioController.h"

namespace Game {
	namespace Controllers {
		class AudioController {
		private:
			std::unique_ptr<Audio::Controllers::AudioController> _audio_controller;
		public:
			AudioController();
			void add_music();
			void play_music();
			void pause_music();
		};
	}
}
