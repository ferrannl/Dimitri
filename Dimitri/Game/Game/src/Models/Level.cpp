#include "Level.h"
using namespace Game;

Models::Level::Level()
{
	_physics_collision_controller = std::make_shared<Game::Controllers::PhysicsCollisionController>();
	_audio_controller = std::make_shared<Controllers::AudioController>();
	_interactables = {};
	_players = {};
	_shapes = {};
	_tiles = {};
	_backgrounds = {};
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
	_height = 1400;
	_width = 4800;

	_physics_collision_controller->setup_world(_height, _width);

	//border
	_shapes.push_back(std::make_shared<PhysicsCollision::Models::Shape>(0, _height, 1, _width, false, false , PhysicsCollision::Enums::ShapeEnum::Square));//top
	_shapes.push_back(std::make_shared<PhysicsCollision::Models::Shape>(0, -1, 1, _width, false, false, PhysicsCollision::Enums::ShapeEnum::Square));//bot
	_shapes.push_back(std::make_shared<PhysicsCollision::Models::Shape>(-1, 0, _height, 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square));//lef
	_shapes.push_back(std::make_shared<PhysicsCollision::Models::Shape>(_width, 0, _height, 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square));//rig

	add_shapes();
}

void Game::Models::Level::add_shapes()
{
	for(std::shared_ptr<Game::Models::IObject> _player : _players)
	{
		_physics_collision_controller->load_shape(_player.get()->get_shape());
	}
	for (std::shared_ptr<Game::Models::IObject> tile : _tiles)
	{
		_physics_collision_controller->load_shape(tile.get()->get_shape());
	}
	for (std::shared_ptr<Game::Models::IInteractable> interactable : _interactables)
	{
		_physics_collision_controller->load_shape(interactable.get()->get_shape());
	}
	for (std::shared_ptr<PhysicsCollision::Models::Shape> shape : _shapes)
	{
		_physics_collision_controller->load_shape(shape);
	}
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Models::Level::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> textures = {};
	std::vector<std::shared_ptr<Graphics::Models::Texture>> temp = _player->get_all_textures();
	textures.insert(textures.end(), temp.begin(), temp.end());

	for (std::shared_ptr<Graphics::Models::Texture> bg : _backgrounds) {
		textures.push_back(bg);
	}
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

void Game::Models::Level::add_object(std::shared_ptr<Game::Models::IObject> tile)
{
	_tiles.push_back(tile);
}

void Game::Models::Level::add_player(std::shared_ptr<Game::Models::IObject> tile)
{
	_player = tile;
	_players.push_back(tile);
}

void Game::Models::Level::add_interactable(std::shared_ptr<Game::Models::IInteractable> tile)
{
	_interactables.push_back(tile);
}

void Game::Models::Level::add_background(std::shared_ptr<Graphics::Models::Sprite> tile)
{
	_backgrounds.push_back(tile);
}

int Game::Models::Level::get_level_height() const
{
	return _height;
}

int Game::Models::Level::get_level_width() const
{
	return _width;
}
