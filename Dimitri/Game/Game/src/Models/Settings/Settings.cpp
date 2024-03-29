#include "Settings.h"
#include <src\Helpers\BasePathHelper.h>

Game::Models::Settings::Settings(int save) : _save(save)
{
	_document_handler = std::make_unique<DocumentHandler::Controllers::DocumentController>();
	_document_handler->CheckIfDirectoryExists(std::string{ Utility::Helpers::get_base_path() + "/assets/saves" });
	_save_path = std::string{ Utility::Helpers::get_base_path() + "/assets/saves/save" + std::to_string(_save) + ".txt" };
	_save_file = _document_handler->Read(_save_path);
	if (_save_file.size() != 0) {
		if(_save_file.at(0).size() != 0){
			_unlocked_level = std::stoi(_save_file.at(0).at(0));
		}
		else {
			_save_file.at(0).push_back(0);
			_document_handler->Write(_save_path, _save_file);
		}
	}
	else {
		std::vector<std::string> v{};
		v.push_back(std::to_string(0));
		_save_file.push_back(v);
		_unlocked_level = 0;
		_document_handler->Write(_save_path, _save_file);
	}
	_current_level = _unlocked_level;
}

int Game::Models::Settings::get_current_level()
{
	return _current_level;
}

void Game::Models::Settings::set_current_level(int current_level)
{
	_current_level = current_level;
}

int Game::Models::Settings::get_save()
{
	return _save;
}

void Game::Models::Settings::set_save(int save)
{
	_save = save;
}

int Game::Models::Settings::get_unlocked_level()
{
	return _unlocked_level;
}

void Game::Models::Settings::set_unlocked_level(int unlocked_level)
{
	_save_file = _document_handler->Read(_save_path);
	if (unlocked_level < _unlocked_level) {
		//negatief progress niet doen
		return;
	}if (unlocked_level > 3) {
		//ophogen wanneer er meer levels zijn
		return;
	}if (unlocked_level -1 != _current_level) {
		//geen extra levels unlocken door een gehaald level te halen
		return;
	}
	_unlocked_level = unlocked_level;
	_save_file.at(0).at(0) = std::to_string(_unlocked_level);
	_document_handler->Write(_save_path, _save_file);
}
