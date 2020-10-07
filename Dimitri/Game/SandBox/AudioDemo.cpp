#include "AudioDemo.h"

void AudioDemo::play_music()
{
    std::string* name = new std::string{ "music" };
    _audio_controller.add_music(name, (SDL_GetBasePath() + std::string{ "resources/audio/beat.wav" }).c_str());
    _audio_controller.play_audio(name);
    SDL_Delay(1000);
    _audio_controller.pause_audio(name);
    SDL_Delay(1000);
    _audio_controller.resume_audio(name);
    SDL_Delay(1000);
    _audio_controller.stop_audio(name);

    
}

void AudioDemo::play_sound()
{
    std::string* name2 = new std::string{ "sound" };
    _audio_controller.add_sound(name2, (SDL_GetBasePath() + std::string{ "resources/audio/beat.wav" }).c_str());
    _audio_controller.play_audio(name2);
    SDL_Delay(250);
    _audio_controller.pause_audio(name2);
    SDL_Delay(250);
    _audio_controller.resume_audio(name2);
    SDL_Delay(250);
    _audio_controller.stop_audio(name2);
}
