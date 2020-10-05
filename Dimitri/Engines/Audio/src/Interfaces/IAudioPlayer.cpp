#include "IAudioPlayer.h"

void Interfaces::IAudioPlayer::play(Models::Audio* audio)
{
    audio->get_audio_adapter()->play();
}

void Interfaces::IAudioPlayer::resume(Models::Audio* audio)
{
    audio->get_audio_adapter()->resume();
}

void Interfaces::IAudioPlayer::pause(Models::Audio* audio)
{
    audio->get_audio_adapter()->pause();
}

void Interfaces::IAudioPlayer::stop(Models::Audio* audio)
{
    audio->get_audio_adapter()->stop();
}