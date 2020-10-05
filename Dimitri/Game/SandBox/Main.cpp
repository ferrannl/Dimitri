#include "PhysicsCollisionDemo.h"
#include "../../Engines/Audio/src/Controllers/AudioController.h"
#include <SDL.h>

int main(int argc, char** argv) 
{
    Controllers::AudioController audio = {};
    std::string* name = new std::string{ "test" };
    audio.add_music(name, (SDL_GetBasePath() + std::string{ "resources/audio/beat.wav" }).c_str());
    audio.play_audio(name);

    PhysicsCollisionDemo demo = {};
    demo.start_demo();
    return 0;
}
