#include "CppUnitTest.h"
#include <src\Controllers\GraphicsController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTests
{
	TEST_CLASS(GraphicsEngine)
	{
	public:
		TEST_METHOD(Creating_Window)
		{
			Graphics::Controllers::GraphicsController ctrl = Graphics::Controllers::GraphicsController{};
			ctrl.create_window("test", 1, 1);

			Assert::IsNotNull(ctrl.get_window().get());
		}
	};
}
