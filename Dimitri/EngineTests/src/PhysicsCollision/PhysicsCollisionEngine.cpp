#include "CppUnitTest.h"
#include <src/Controllers/WorldController.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTests
{
	TEST_CLASS(PhysicsCollisionEngine)
	{
	private:
		std::shared_ptr<PhysicsCollision::Models::Shape> create_shape()
		{
			PhysicsCollision::Controllers::WorldController ctr = PhysicsCollision::Controllers::WorldController{};
			std::shared_ptr<PhysicsCollision::Models::Shape> shape = ctr.create_shape(PhysicsCollision::Enums::ShapeEnum::Square, 8.0f, 10.0f, 20.0f, 20.0f, true);

			return shape;
		}

		PhysicsCollision::Controllers::WorldController create_world_setup()
		{
			PhysicsCollision::Controllers::WorldController ctr = PhysicsCollision::Controllers::WorldController{};

			ctr.setup_world(1080, 720);
			ctr.create_shape(PhysicsCollision::Enums::ShapeEnum::Square, 8.0f, 10.0f, 1.0f, 1.0f, true);
			ctr.create_shape(PhysicsCollision::Enums::ShapeEnum::Square, 8.0f, 9.0f, 1.0f, 1.0f, false);


			return ctr;
		}
	public:
		TEST_METHOD(Create_Shape)
		{
			std::shared_ptr<PhysicsCollision::Models::Shape> shape = create_shape();

			Assert::IsNotNull(shape.get());
			Assert::AreEqual(true, shape->get_is_dynamic());
		}

		TEST_METHOD(Gravity)
		{
			PhysicsCollision::Controllers::WorldController ctr = create_world_setup();

			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes = ctr.get_shapes();

			ctr.simulate();
			
			Assert::AreNotEqual(10.0f, shapes[0]->get_y());
		}

		TEST_METHOD(Move_Left)
		{
			PhysicsCollision::Controllers::WorldController ctr = create_world_setup();

			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes = ctr.get_shapes();
			shapes[0]->get_shape_facade()->move_x(-1);
			ctr.simulate();

			Assert::AreNotEqual(8.0f, shapes[0]->get_x());
		}

		TEST_METHOD(Move_Right)
		{
			PhysicsCollision::Controllers::WorldController ctr = create_world_setup();

			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes = ctr.get_shapes();
			shapes[0]->get_shape_facade()->move_x(1);
			ctr.simulate();

			Assert::AreNotEqual(8.0f, shapes[0]->get_x());
		}

		TEST_METHOD(Move_Up)
		{
			PhysicsCollision::Controllers::WorldController ctr = create_world_setup();

			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes = ctr.get_shapes();
			shapes[0]->get_shape_facade()->move_y();
			ctr.simulate();

			Assert::AreNotEqual(10.0f, shapes[0]->get_y());
		}

		TEST_METHOD(Collision)
		{
			PhysicsCollision::Controllers::WorldController ctr = create_world_setup();

			std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes = ctr.get_shapes();

			for (int i = 0; i < 10; i++)
			{
				ctr.simulate();
			}

			Assert::AreEqual((int)(shapes[1]->get_y() + shapes[1]->get_height()), (int)shapes[0]->get_y());
		}
	};
}
