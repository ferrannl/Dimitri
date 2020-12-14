#pragma once
#include "../Abstract/Interactable.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class Switch
		* \brief Class contains the methods and data of the Switch
		*/
		class Switch : public Models::Interactable {
		private:
			/**
			* \brief The x coordinate of the beam
			*/
			std::vector<std::tuple<int, int>> _light_positions;

		public:
			Switch(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center);


			/**
			* \brief Initializes Textures
			*/
			void initialize_textures();

			/**
			* \brief Updates the object when interacted with
			*/
			void interact(Controllers::LevelController* ctrl = NULL);

			/**
			* \brief Sets the x and y coordinate of the lightbeam location
			*/
			void set_light(const std::tuple<int, int> light_pos);
		};
	}
}