#pragma once

#include <iostream>
#include <src\Controllers\GraphicsController.h>
#include <src\Controllers\AudioController.h>
#include <src\Controllers\WorldController.h>
#include <src\Controllers\InputController.h>
#include <src\Helpers\BasePathHelper.h>

#include <iostream>
#include <vector>
#include <tuple>

#include <chrono>
#include <thread>

namespace Demo {
	class Demo : public Utility::Interfaces::IObserver<Input::Enums::EventEnum>, public std::enable_shared_from_this<Demo> {
	private:
		std::shared_ptr<Graphics::Controllers::GraphicsController> _g_ctlr;
		std::shared_ptr<Audio::Controllers::AudioController> _a_ctlr;
		std::shared_ptr<PhysicsCollision::Controllers::WorldController> _w_ctlr;
		std::shared_ptr<Input::Controllers::InputController> _i_ctlr;

		std::shared_ptr<Graphics::Models::Texture> _plaatje;
		std::shared_ptr<PhysicsCollision::Models::Shape> _shape;

	public:
		Demo();
		void setup();
		void run();

		void update(const Input::Enums::EventEnum& object);
	};
}