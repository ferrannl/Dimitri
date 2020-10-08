#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"

int main(int argc, char** argv) 
{
    AudioDemo audio_demo = {};
    audio_demo.play_music();
    audio_demo.play_sound();

    PhysicsCollisionDemo demo = {};
    demo.start_demo();

    return 0;
}
