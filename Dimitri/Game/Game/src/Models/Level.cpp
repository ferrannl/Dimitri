#include "Level.h"
using namespace Game;

Models::Level::Level(const std::shared_ptr<Controllers::AudioController> audio_controller, const int width, const int height) : _audio_controller(audio_controller)
{
	_width = width;
	_height = height;
	_speed = 2;
	_physics_collision_controller = std::make_shared<Game::Controllers::PhysicsCollisionController>();
	_interactables = {};
	_shapes = {};
	_tiles = {};
	_backgrounds = {};
	_updatables = {};
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
	_physics_collision_controller->setup_world(_height, _width);

	add_shapes();
}

void Game::Models::Level::add_shapes()
{
	_physics_collision_controller->load_shape(_player.get()->get_shape());

	for (std::shared_ptr<Game::Models::Object> tile : _tiles)
	{
		_physics_collision_controller->load_shape(tile.get()->get_shape());
	}
	for (std::shared_ptr<Game::Models::Interactable> interactable : _interactables)
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
	for (std::shared_ptr<Object> tile : _tiles)
	{
		temp = tile->get_all_textures();
		textures.insert(textures.end(), temp.begin(), temp.end());
	}
	for (std::shared_ptr<Object> interactable : _interactables)
	{
		temp = interactable->get_all_textures();
		textures.insert(textures.end(), temp.begin(), temp.end());

	}
	for (std::shared_ptr<Updatable> updatables : _updatables)
	{
		updatables->set_angle(_speed);
		if (updatables->get_type() == Game::Enums::TypeEnum::PLAYER)
		{

		}
		temp = updatables->get_all_textures();
		textures.insert(textures.end(), temp.begin(), temp.end());
	}
	return textures;
}

std::shared_ptr<Game::Models::Player> Game::Models::Level::get_player() const
{
	return _player;
}

std::vector<std::shared_ptr<Game::Models::Object>> Game::Models::Level::get_tiles() const
{
	return _tiles;
}

std::vector<std::shared_ptr<Game::Models::Interactable>> Game::Models::Level::get_interactables() const
{
	return _interactables;
}

std::vector<std::shared_ptr<Game::Models::Updatable>> Game::Models::Level::get_updatables() const
{
	return _updatables;
}

std::shared_ptr<Game::Controllers::PhysicsCollisionController> Game::Models::Level::get_physics_collision_controller() const
{
	return _physics_collision_controller;
}

void Game::Models::Level::simulate()
{
	_physics_collision_controller->simulate();
}

void Game::Models::Level::add_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape)
{
	_shapes.push_back(shape);
}

void Game::Models::Level::add_tile(std::shared_ptr<Game::Models::Object> tile)
{
	_tiles.push_back(tile);
}

void Game::Models::Level::add_player(std::shared_ptr<Game::Models::Player> tile)
{
	_player = tile;
	_updatables.push_back(tile);
}

void Game::Models::Level::add_interactable(std::shared_ptr<Game::Models::Interactable> tile)
{
	_interactables.push_back(tile);
}

void Game::Models::Level::add_updatable(std::shared_ptr<Game::Models::Updatable> tile)
{
	_updatables.push_back(tile);
}

void Game::Models::Level::add_background(std::shared_ptr<Graphics::Models::Sprite> tile)
{
	_backgrounds.push_back(tile);
}

int Game::Models::Level::get_height() const
{
	return _height;
}

int Game::Models::Level::get_width() const
{
	return _width;
}