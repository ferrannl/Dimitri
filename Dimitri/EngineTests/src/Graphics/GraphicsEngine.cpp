#include "CppUnitTest.h"
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTests
{
	TEST_CLASS(GraphicsEngine)
	{
	private:
		Graphics::Controllers::GraphicsController create_window() {
			Graphics::Controllers::GraphicsController ctrl = Graphics::Controllers::GraphicsController{};
			ctrl.create_window("test", 1, 1);
			
			return ctrl;
		}
	public:
		TEST_METHOD(Creating_Window)
		{
			Graphics::Controllers::GraphicsController ctrl = create_window();

			Assert::IsNotNull(ctrl.get_window().get());
		}

		TEST_METHOD(Add_Sprite)
		{
			Graphics::Controllers::GraphicsController ctrl = create_window();

			std::shared_ptr<Graphics::Models::Texture> texture = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 100, 100, 0, "no path", Graphics::Enums::FlipEnum::HORIZONTAL, false);
			ctrl.add_texture(texture);

			Assert::IsTrue(ctrl.get_textures().at(0) == texture);
		}

		TEST_METHOD(Remove_Texture)
		{
			Graphics::Controllers::GraphicsController ctrl = create_window();

			std::shared_ptr<Graphics::Models::Texture> texture = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 100, 100, 0, "no path", Graphics::Enums::FlipEnum::HORIZONTAL, false);
			ctrl.add_texture(texture);

			ctrl.remove_texture(texture);

			Assert::IsTrue(ctrl.get_textures().size() == 0);
		}
	};
}
