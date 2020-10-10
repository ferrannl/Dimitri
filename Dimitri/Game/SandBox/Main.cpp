#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"

int main(int argc, char** argv) 
{
    AudioDemo audio_demo = {};
  
    std::thread audio_thread(&AudioDemo::play_music, audio_demo);

    std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();
    demo->subscribe_to_input(demo);
    demo->start_demo();
    
    audio_thread.join();
    return 0;
}