#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"
#include "InputDemo.h"

int main(int argc, char** argv) 
{
   /* AudioDemo audio_demo = {};
    audio_demo.play_music();
    audio_demo.play_sound();*/
  
    std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();

    InputDemo inputdemo = {};
    inputdemo.get_input_controller()->subscribe(demo);

    std::thread input_thread(&Controllers::InputController::poll_events, inputdemo.get_input_controller());
    demo->start_demo();
   

    return 0;
}