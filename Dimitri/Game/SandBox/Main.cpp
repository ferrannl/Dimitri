#include "PhysicsCollisionDemo.h"

int main(int argc, char** argv) 
{

    

    std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();
    demo->subscribe_to_input(demo);
    demo->start_demo();
    
    return 0;
}