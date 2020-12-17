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
		* \class Settings
		* \brief Class contains the settings for level and logic for saves
		*/
		class Settings {
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
			Settings(int save);
			/**
			* \brief Returns current level
			*/
			int get_current_level();
			/**
			* \brief Sets current level
			*/
			void set_current_level(int current_level);

			/**
			* \brief Returns save
			*/
			int get_save();
			/**
			* \brief Sets save
			*/
			void set_save(int save);

			/**
			* \brief Returns unlocked level
			*/
			int get_unlocked_level();
			/**
			* \brief Sets unlocked level
			*/
			void set_unlocked_level(int unlocked_level);
		};
	}
}
