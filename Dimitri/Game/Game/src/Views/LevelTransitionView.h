#pragma once
#include <..\Game\Game\src\Views\View.h>
#include <src\Helpers\BasePathHelper.h>
#include "../Models/IObjects/Lamp.h"
#include "../Models/IObjects/Floor.h"
#include "../Models/Updatables/LightBeam.h"
#include "../Models/Updatables/Player.h"
#include "../Controllers/PhysicsCollisionController.h"
#include "src/Models/Shape.h"
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Views
	* \brief Namespace for the views in the game
	*/
	namespace Views {
		/**
		* \class LevelTransitionView
		* \brief Class contains the methods to draw the level transition
		*/
		class LevelTransitionView : public View {
		private:
			/**
			* \brief An instance of the Player
			*/
			std::unique_ptr<Models::Player> _player;

			/**
			* \brief An instance of the LightBeam
			*/
			std::unique_ptr<Models::LightBeam> _lightbeam;

			/**
			* \brief An instance of the PhysicsCollisionController
			*/
			std::shared_ptr<Graphics::Models::Sprite> _mask;

			/**
			* \brief An instance of the PhysicsCollisionController
			*/
			std::unique_ptr<Controllers::PhysicsCollisionController> _pc_ctrl;

			/**
			* \brief A counter to keep track of the ticks
			*/
			int _counter;

			/**
			* \brief The opacity of the fade in and out effect
			*/
			int _fade_opacity;
		public:
			LevelTransitionView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes Textures
			*/
			void init_textures();

			/**
			* \brief Updates the textures
			*/
			void update() override;

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;
		};
	}
}