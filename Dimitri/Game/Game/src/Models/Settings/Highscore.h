#pragma once
#include <memory>
#include <src/Controllers/DocumentController.h>

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
		* \class Highscore
		* \brief Class contains the information for highscore 
		*/
		class Highscore {
		private:
			/**
			* \brief Current save
			*/
			int _save;

			/**
			* \brief Current Level
			*/
			int _current_level;

			/**
			* \brief Current Level
			*/
			int _unlocked_level;

			/**
			* \brief Document Handler
			*/
			std::unique_ptr<DocumentHandler::Controllers::DocumentController> _document_handler;

			/**
			* \brief Path to save file
			*/
			std::string _save_path;

			/**
			* \brief Save File
			*/
			std::vector<std::vector<int>> _save_file;

		public:
			Highscore(int save);
			/**
			* \brief Returns current level
			*/
			int get_current_level();
			/**
			* \brief Sets current level
			*/
			void set_current_level(int current_level);
		};
	}
}
