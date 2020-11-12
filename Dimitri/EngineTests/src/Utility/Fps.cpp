#include "CppUnitTest.h"
#include <src/Time/Fps.h>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std::this_thread;
using namespace std::chrono_literals;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTests
{
	TEST_CLASS(Fps)
	{
	public:
		TEST_METHOD(Should_Update_Ten_Times_Per_Second)
		{
			auto fps = Utility::Time::Fps();
			for (int i = 0; i < 9; i++) {
				fps.update();
			}
			sleep_for(1100ms);
			fps.update();
			Assert::IsTrue(fps.get() == 10);
		}
	};
}
