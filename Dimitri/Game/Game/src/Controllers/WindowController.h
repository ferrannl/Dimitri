#pragma once
#include <src\Controllers\GraphicsController.h>
#include "../Views/CreditsView.h"
#include <src\Interfaces\IObserver.h>
#include "../Models/InputEvent.h"
#include "../Views/CreditsView.h"

namespace Game {
	namespace Controllers {
		class WindowController : public Utility::Interfaces::IObserver<Game::Models::InputEvent> {
		private:
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			std::unique_ptr<Views::CreditsView> _credits_view;
		public:
			WindowController();
			void update(const Game::Models::InputEvent& object);
		};
	}
}