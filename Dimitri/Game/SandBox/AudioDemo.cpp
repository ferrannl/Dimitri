#include "AudioDemo.h"

void AudioDemo::play_music()
{
    std::string* name = new std::string{ "music" };
    std::filesystem::path asset = std::filesystem::current_path() / "assets" / "audio" / "beat.wav";

    _audio_controller.add_music(name, asset.string().c_str());
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
    std::string* name = new std::string{ "sound" };
    std::filesystem::path asset = std::filesystem::current_path() / "assets" / "audio" / "beat.wav";

    _audio_controller.add_sound(name, asset.string().c_str());
    _audio_controller.play_audio(name);
    SDL_Delay(250);
    _audio_controller.pause_audio(name);
    SDL_Delay(250);
    _audio_controller.resume_audio(name);
    SDL_Delay(250);
    _audio_controller.stop_audio(name);
}
