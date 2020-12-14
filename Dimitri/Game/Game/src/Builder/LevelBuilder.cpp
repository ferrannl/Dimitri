#include "LevelBuilder.h"
#include <any>
#include <optional>

using namespace Game;

std::shared_ptr<Models::Level> Builder::LevelBuilder::build(std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> level_layers, const std::shared_ptr<Controllers::AudioController> audio_controller, const std::shared_ptr<Controllers::WindowController> window_controller)
{
    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = level_layers.first;
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = level_layers.second;

    int level_height = (tiles.at(0).second.size() - 1) * TILE_SIZE;
    int level_width = (tiles.at(0).second.at(0).size()) * TILE_SIZE;

    std::shared_ptr<Models::Level> level = std::make_shared<Models::Level>(audio_controller, window_controller, level_width, level_height);

    build_background(level);
    build_borders(level);

    for (std::pair<int, std::vector<std::vector<int>>> tileset : tiles) {
        _tile_builder.build(level, tileset, objects);
    }

    return level;
}

void Builder::LevelBuilder::build_background(std::shared_ptr<Models::Level>& level) {
    int bg_height = 720;
    int bg_width = 680;
    int top_height = 80;
    int top_width = bg_width;

    int x = 0;
    int y = 0;

    while (x < level->get_width()) {
        level->add_background(_background_factory.create(Enums::TypeEnum::BG, x, y, 0, bg_height, bg_width, Enums::DirectionEnum::NONE));

        y += bg_height;

        while (y <= level->get_height()) {
            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP1, x, y, 0, top_height, top_width, Enums::DirectionEnum::NONE));
            y += top_height;

            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP2, x, y, 0, top_height, top_width, Enums::DirectionEnum::NONE));
            y += top_height;
        }

        y = 0;
        x += bg_width;
    }
}

void Game::Builder::LevelBuilder::build_borders(std::shared_ptr<Game::Models::Level>& level)
{
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0.0f, level->get_height(), 1.0f, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //top
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0.0f, -1.0f, 1.0f, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //bot
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(-1, 0, level->get_height(), 1.0f, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //lef
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(level->get_width(), 0.0f, level->get_height(), 1.0f, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //rig
}
