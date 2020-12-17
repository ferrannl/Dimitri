#include "LevelBuilder.h"
#include <any>
#include <optional>

using namespace Game;

std::shared_ptr<Models::Level> Builder::LevelBuilder::build(const std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>>& level_layers, const std::shared_ptr<Controllers::AudioController> audio_controller, const std::shared_ptr<Controllers::WindowController> window_controller)
{
    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = level_layers.first;
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = level_layers.second;

    int level_height = (tiles.at(0).second.size()) * TILE_SIZE;
    int level_width = (tiles.at(0).second.at(0).size()) * TILE_SIZE;

    std::shared_ptr<Models::Level> level = std::make_shared<Models::Level>(audio_controller, window_controller, level_width, level_height);

    build_borders(level);

    for (std::pair<int, std::vector<std::vector<int>>> tileset : tiles) {
        if (tileset.first == 1) {
            _background_builder.build(level, tileset, objects);
        }
        else {
            _tile_builder.build(level, tileset, objects);
        }
    }

    return level;
}

void Game::Builder::LevelBuilder::build_borders(std::shared_ptr<Game::Models::Level>& level)
{
	level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0, level->get_height(), 1, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //top
	level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0, -1, 1, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //bot
	level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(-1, 0, level->get_height(), 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //lef
	level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(level->get_width(), 0, level->get_height(), 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //rig
}
