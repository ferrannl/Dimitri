#include "Level.h"
using namespace Game;

Models::Level::Level()
{
	_physics_collision_controller = std::make_shared<Game::Controllers::PhysicsCollisionController>();
	_audio_controller = std::make_shared<Controllers::AudioController>();
	_tiles = {};
	_borders = {};
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
	_player = std::make_shared<Player>(200, 200, 1, 50, 50, Game::Enums::StateEnum::RIGHT);
	_player->set_shape(_physics_collision_controller->create_shape(_player->get_x(), _player->get_y(), _player->get_width(), _player->get_height(), true, false));

	//floor
	std::shared_ptr<IObject> tile = std::make_shared<Wall>(0, 0, 1, 25, 25, Game::Enums::StateEnum::LEFT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(25, 0, 1, 25, 1030, Game::Enums::StateEnum::HORIZONTAL);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(1055, 0, 1, 25, 25, Game::Enums::StateEnum::RIGHT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	_background = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 720, 1080, 0,Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::HORIZONTAL);
	_background->set_visible(true);

	//platform 1
	tile = std::make_shared<Wall>(200, 150, 1, 25, 25, Game::Enums::StateEnum::LEFT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(225, 150, 1, 25, 100, Game::Enums::StateEnum::HORIZONTAL);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(325, 150, 1, 25, 25, Game::Enums::StateEnum::RIGHT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);
	//platform 2
	tile = std::make_shared<Wall>(400, 300, 1, 25, 25, Game::Enums::StateEnum::LEFT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(425, 300, 1, 25, 100, Game::Enums::StateEnum::HORIZONTAL);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(525, 300, 1, 25, 25, Game::Enums::StateEnum::RIGHT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);
	//platform 3
	tile = std::make_shared<Wall>(600, 450, 1, 25, 25, Game::Enums::StateEnum::LEFT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(625, 450, 1, 25, 100, Game::Enums::StateEnum::HORIZONTAL);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(725, 450, 1, 25, 25, Game::Enums::StateEnum::RIGHT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	tile = std::make_shared<Wall>(725, 450, 1, 25, 25, Game::Enums::StateEnum::RIGHT);
	tile->set_shape(_physics_collision_controller->create_shape(tile->get_x(), tile->get_y(), tile->get_width(), tile->get_height(), false, false));
	_tiles.push_back(tile);

	//interactables
	std::shared_ptr<IInteractable> interactable = std::make_shared<Switch>(650, 475, 1, 25, 25, Game::Enums::StateEnum::LEFT);
	interactable->set_shape(_physics_collision_controller->create_shape(interactable->get_x(), interactable->get_y(), interactable->get_width(), interactable->get_height(), true, true));
	_interactables.push_back(interactable);

	//border 
	_borders.push_back(_physics_collision_controller->create_shape(0, 721, 1080, 1, false, false));//top
	_borders.push_back(_physics_collision_controller->create_shape(0, -1, 1080, 1, false, false));//bottom
	_borders.push_back(_physics_collision_controller->create_shape(-1, 0, 1, 720, false, false));//left
	_borders.push_back(_physics_collision_controller->create_shape(1081, 0, 1, 720, false, false));//right
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Models::Level::get_textures() const
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
	for (std::shared_ptr<IObject> interactable : _interactables)
	{
		temp = interactable->get_all_textures();
		textures.insert(textures.end(), temp.begin(), temp.end());
	}
	return textures;
}

std::shared_ptr<Game::Models::IObject> Game::Models::Level::get_player() const
{
	return _player;
}

std::vector<std::shared_ptr<Game::Models::IInteractable>> Game::Models::Level::get_interactables() const
{
	return _interactables;
}

std::shared_ptr<Game::Controllers::PhysicsCollisionController> Game::Models::Level::get_physics_collision_controller() const
{
	return _physics_collision_controller;
}

void Game::Models::Level::simulate()
{
	_physics_collision_controller->simulate();
}
