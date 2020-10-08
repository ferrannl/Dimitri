#include "AudioDemo.h"

void AudioDemo::play_music()
{
    const std::string name = std::string("music");
    _audio_controller->add_music(name, (SDL_GetBasePath() + std::string{ "assets/audio/beat.wav" }).c_str());
    _audio_controller->play_audio(name);
    SDL_Delay(1000);
    _audio_controller->pause_audio(name);
    SDL_Delay(1000);
    _audio_controller->resume_audio(name);
    SDL_Delay(1000);
    _audio_controller->stop_audio(name);

    
}

void AudioDemo::play_sound()
{
    const std::string name = std::string( "sound" );
    _audio_controller->add_sound(name, (SDL_GetBasePath() + std::string{ "assets/audio/beat.wav" }).c_str());
    _audio_controller->play_audio(name);
    SDL_Delay(250);
    _audio_controller->pause_audio(name);
    SDL_Delay(250);
    _audio_controller->resume_audio(name);
    SDL_Delay(250);
    _audio_controller->stop_audio(name);
}
