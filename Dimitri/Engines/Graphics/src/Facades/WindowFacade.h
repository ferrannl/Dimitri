#pragma once
#include "../Models/Sprite.h"
#include "../Models/Text.h"
#include "../Adapters/FlipEnumAdapter.h"
#include "src/Time/Fps.h"
#include "src/Time/Timer.h"
#include <tuple>

struct SDL_Window;
struct SDL_Renderer;

/**
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Facades
	* \brief Namespace for the facades in the graphics engine
	*/
	namespace Facades {
		/**
		* \class WindowFacade
		* \brief Class contains the references to the SDL_Window
		*/
		class WindowFacade {
		private:
			/**
			* \brief Contains the fps of the Window
			*/
			std::unique_ptr<Utility::Time::Fps> _fps;

			/**
			* \brief Contains a timer object
			*/
			std::shared_ptr<Utility::Time::Timer> _timer;

			/**
			* \brief An instance of SDL_Window with a custom destructor
			*/
			std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;

			/**
			* \brief An instance of SDL_Renderer with a custom destructor
			*/
			std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
			
			/**
			* \brief The adapter that converts the SDL_FlipEnum to FlipEnum
			*/
			Adapters::FlipEnumAdapter _flip_enum_adapter;

			/**
			* \brief The height of the Window
			*/
			int _window_height;

			/**
			* \brief The width of the Window
			*/
			int _window_width;

			/**
			* \brief The camera position of the Window
			* The standard position of the camera is 0,0
			* \return std::tuple<width, height>
			*/
			std::tuple<float, float> _camera_pos;


			/**
			* \brief The width and height of the Scene
			* \return std::tuple<width, height>
			*/
			std::tuple<float, float> _scene_size;

		public:
			WindowFacade();

			/**
			* \brief Creates the instance of SDL_Renderer
			*/
			int create_renderer();

			/**
			* \brief Returns the timer ticks 
			*/
			uint32_t get_ticks();

			/**
			* \brief Creates the instance of SDL_Window
			*/
			int create_window(const std::string& title, float height, float width);

			/**
			* \brief Creates a TextureFacade or adds an already created TextureFacade if Texture matches
			*/
			void create_texture(const std::shared_ptr<Models::Texture>& texture, const std::shared_ptr<Models::Texture>& matching_texture);

			/**
			* brief Destroys the SDL_Window
			*/
			void destroy();

			/**
			* \brief Updates the window with all the sprites in the given list
			*/
			void update_window(const std::vector<std::shared_ptr<Models::Texture>> textures);

			/**
			* \brief Returns the fps of the Window
			*/
			int get_fps();

			/**
			* brief Updates camera position
			*/
			void set_camera_pos(float x, float y);

			/**
			* brief Returns camera position
			*/
			std::tuple<float, float> get_camera_pos() const;

			/**
			* brief Sets scene size
			*/
			void set_scene_size(float height, float width);

			/**
			* brief Returns scene size
			*/
			std::tuple<float, float> get_scene_size() const;

			/**
			* \brief Returns the timer
			*/
			std::shared_ptr<Utility::Time::Timer> get_timer() const;
		};
	}
}