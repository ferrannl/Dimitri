#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"
#include <windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
   /* AudioDemo audio_demo = {};
  
    std::thread audio_thread(&AudioDemo::play_music, audio_demo);*/

    std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();
    demo->subscribe_to_input(demo);
    demo->start_demo();
    
    //audio_thread.join();
    return 0;
}