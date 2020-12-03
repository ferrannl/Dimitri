//#pragma once
//#include <SDL.h>
//#include <stdint.h>
///**
//* \namespace Game
//* \brief Namespace for the game
//*/
//namespace Game {
//	/**
//	* \namespace Game::Models
//	* \brief Namespace for the models in the game
//	*/
//	namespace Models {
//		/**
//		* \class Timer
//		* \brief Class contains the data of the Timer
//		*/
//		class Timer {
//		public:
//			Timer(const std::shared_ptr<Controllers::WindowController> window_controller);
//			void start();
//			void stop();
//			void pause();
//			void unpause();
//
//			Uint32 getTicks();
//
//			bool is_started();
//			bool is_paused();
//
//			/*std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures();
//
//			void initialize_textures();*/
//
//			/**
//			* \brief Updates the object when interacted with
//			*/
//			void update_object(Controllers::LevelController* ctrl = NULL);
//			
//		private:
//			std::vector<std::shared_ptr<Graphics::Models::Texture>> _textures;
//			std::shared_ptr<Controllers::WindowController> _window_controller;
//			Uint32 _pause_ticks;
//			Uint32 _start_ticks;
//			
//			bool _started;
//			bool _paused;
//		};
//
//	}
//}