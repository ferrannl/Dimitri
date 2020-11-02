#include "Level.h"
using namespace Game;

Models::Level::Level()
{
	_audio_controller = std::make_shared<Controllers::AudioController>();
	_tiles = {};
}

void Models::Level::add_music(std::string audio_name, std::string path)
{
	_audio_controller->add_music(audio_name, path);
}

void Game::Models::Level::add_sound(std::string audio_name, std::string path)
{
	_audio_controller->add_sound(audio_name, path);
}

void Models::Level::play_music(std::string audio_name)
{
	_audio_controller->play_audio(audio_name);
}

void Models::Level::stop_music(std::string audio_name)
{
	_audio_controller->stop_audio(audio_name);
}

void Game::Models::Level::pause_music(std::string audio_name)
{
	_audio_controller->pause_audio(audio_name);
}

void Game::Models::Level::resume_music(std::string audio_name)
{
	_audio_controller->resume_audio(audio_name);
}


void Game::Models::Level::load_objects()
{
	//Here a file is loaded/parsed and turned into a level
	_player = std::make_shared<Player>(200, 200, 1, 150, 75);
	_player->set_state("right");

	std::shared_ptr<IObject> tile = std::make_shared<Wall>(200, 100, 1, 50, 50);
	tile->set_state("left");
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(250, 100, 1, 50, 50);
	tile->set_state("default");
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(300, 100, 1, 50, 50);
	tile->set_state("right");
	_tiles.push_back(tile);

	_background = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 720, 1080, 0,Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::HORIZONTAL);
	_background->set_visible(true);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Models::Level::get_textures()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> textures = {};
	std::vector<std::shared_ptr<Graphics::Models::Texture>> temp = _player->get_all_textures();
	textures.insert(textures.end(), temp.begin(), temp.end());
	textures.push_back(_background);
	for (std::shared_ptr<IObject> tile : _tiles)
	{
		temp = tile->get_all_textures();
		textures.insert(textures.end(), temp.begin(), temp.end());
	}
	return textures;
}

std::shared_ptr<Game::Models::IObject> Game::Models::Level::get_player()
{
	return _player;
}
