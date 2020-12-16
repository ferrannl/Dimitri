#pragma once
#include <vector>
#include <memory>
#include <src/Models/Texture.h>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		* \class AdvertisementController
		* \brief Class contains the methods to interact with advertisement view
		*/
		class AdvertisementController {
		private:
			/**
			* \brief The height of the scene
			*/
			int _scene_height;

			/**
			* \brief The width of the scene
			*/
			int _scene_width;

			/**
			* \brief A list of all the advertisements
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> _advertisements;
		public:
			AdvertisementController(int sceneheight, int scenewidth);

			/**
			* \brief Loads the Buttons
			*/
			void load_advertisements();

			/**
			* \brief Returns the Textures from the Buttons
			*/
			const std::vector<std::shared_ptr<Graphics::Models::Texture>>& get_textures() const;

		};
	}
}
