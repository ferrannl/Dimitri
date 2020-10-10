#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"
#include "InputDemo.h"

int main(int argc, char** argv) 
{
    AudioDemo audio_demo = {};
  
    std::thread audio_thread(&AudioDemo::play_music, audio_demo);

    std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();

    InputDemo inputdemo = {};
    inputdemo.get_input_controller()->subscribe(demo);

    demo->start_demo();
    std::thread demo_thread(&PhysicsCollisionDemo::run, demo);
    inputdemo.get_input_controller()->poll_events();
    
    demo_thread.join();
    audio_thread.join();
    return 0;
}