#pragma once
#include "../Views/View.h"
#include <src\Helpers\BasePathHelper.h>
#include <string> 
#include <algorithm>

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
		* \class HighscoreView
		* \brief Class contains the methods to get and check the personal best of a player
		*/
		class HighscoreView : public View {
		public:
			HighscoreView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller);

			/**
			* \brief Initializes Textures
			*/
			void init_textures();

			/**
			* \brief Returns the visible state of the View
			*/
			bool is_visible() const override;

			/**
			* \brief Adds a record to the HighscoreView
			*/
			void add_record(std::string record);

		private:
			/**
			* \brief Vector to save all the known times of a player
			*/
			std::vector<std::string> _record_times;


		};
	}
}