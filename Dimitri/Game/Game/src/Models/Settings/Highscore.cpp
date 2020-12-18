#include "Highscore.h"
#include <src\Helpers\BasePathHelper.h>
#include <algorithm>

Game::Models::Highscore::Highscore(int save) : _save{save}
{
	_document_handler = std::make_unique<DocumentHandler::Controllers::DocumentController>();
	_save_path = std::string{ Utility::Helpers::get_base_path() + "/assets/saves/save" + std::to_string(_save) + ".txt" };
	_save_file = _document_handler->Read(_save_path);
	if (_save_file.size() != 0) {
		//checks if unlocked level is saved
		if (_save_file.at(0).size() == 0) {
			_save_file.at(0).push_back(std::to_string(0));
		}
		//checks if highscores are initialized
		if (_save_file.size() == 1) {
			for (int i = 0; i < 4; i++) {	
				std::vector<std::string> h{};
				h.push_back(std::to_string(i));
				_save_file.push_back(h);
			}
		}
		_document_handler->Write(_save_path, _save_file);
	}
	else {
		//initializes entire doc
		std::vector<std::string> v{};
		v.push_back(std::to_string(0));
		_save_file.push_back(v);
		for (int i = 0; i < 4; i++) {
			std::vector<std::string> h{};
			h.push_back(std::to_string(i));
			_save_file.push_back(h);
		}
		_document_handler->Write(_save_path, _save_file);
	}
}

std::vector<std::string> Game::Models::Highscore::get_highscores(int level) const
{
	std::vector<std::string> result{};
	bool first = true;
	for (auto score : _save_file.at(level + 1)) {
		if (first) {
			//dont take the first int
			first = false;
		}
		else {
			result.push_back(score);
		}
	}
	std::sort(result.begin(), result.end());
	return result;
}

void Game::Models::Highscore::add_highscore(int level, const std::string& highscore)
{
	_save_file = _document_handler->Read(_save_path);
	_save_file.at(level + 1).push_back(highscore);
	_document_handler->Write(_save_path, _save_file);
}
