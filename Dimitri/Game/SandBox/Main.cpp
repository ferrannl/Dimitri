#include "PhysicsCollisionDemo.h"
#include "AudioDemo.h"
void play_music();

int wmain()
{
	std::thread audio_thread(play_music);

	std::shared_ptr<PhysicsCollisionDemo> demo = std::make_shared<PhysicsCollisionDemo>();
	demo->subscribe_to_input(demo);
	demo->start_demo();

	audio_thread.join();
	return 0;
}

void play_music()
{
	AudioDemo audio_demo = {};
	audio_demo.play_music();
}