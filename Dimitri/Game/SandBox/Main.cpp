#include "PhysicsCollisionDemo.h"
#include "../../Engines/Audio/src/Handlers/MusicPlayer.h"

int main(int argc, char** argv) 
{
    Handlers::MusicPlayer music = {};
    music.init();
    music.play_music();

    PhysicsCollisionDemo demo = {};
    demo.start_demo();

    music.close();

    return 0;
}
