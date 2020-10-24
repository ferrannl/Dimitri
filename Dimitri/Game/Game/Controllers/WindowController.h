#pragma once
#include "../../../Engines/Graphics/src/Controllers/GraphicsController.h"

namespace Game {
	namespace Controllers {
		class WindowController {
		private:
			std::unique_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
		public:
			WindowController();
		};
	}
}