#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace Game {
	namespace Views {
		class CreditsView {
		private:
			/**
			*	Graphics controller to update window
			*/
			std::shared_ptr<Graphics::Controllers::GraphicsController> _graphics_controller;
			/**
			*	Textures for current view
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
			/**
			*	Draw thread for updating window in background thread
			*/
			std::thread draw_thread;
		public:
			CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);
			/**
			*	If view is currently being used or not
			*/
			bool is_open; // TODO: delete var when screen navigation is implemented

			/**
			*	Initializes textures
			*/
			void init_textures();
			/**
			*	Open window loads textures into graphics
			*/
			void open();
			/**
			*	Removes textures from window
			*/
			void close();
			/**
			*	Loop for updating window
			*/
			void draw();
		};
	}
}
