#pragma once
#include "InputController.h"
#include "WindowController.h"
#include "LevelController.h"
#include "../Models/Level.h"
#include <memory>
namespace Game {
	namespace Controllers {
		class MainController {
		private:
			/**
			*	Level model
			*/
			std::shared_ptr<Models::Level> _level;
			/**
			*	Input Controller
			*/
			std::shared_ptr<Controllers::InputController> _input_controller;
			/**
			*	Window Controller
			*/
			std::shared_ptr<Controllers::WindowController> _window_controller;
			/**
			*	Level Controller
			*/
			std::shared_ptr<Controllers::LevelController> _level_controller;
		public:
			MainController();

			/**
			*	Starts polling input controller
			*/
			void run();
		};
	}
}