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
			std::vector<std::vector<std::string>> _save_file;

		public:
			Highscore(int save);
			
			/**
			* \brief Returns current highscores for level
			*/
			std::vector<std::string> get_highscores(int level) const;

			/**
			* \brief Add highscore to level
			*/
			void add_highscore(int level, const std::string& highscore);
		};
	}
}
