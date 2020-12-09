#include "LevelBuilder.h"
#include <any>
#include <optional>

using namespace Game;

std::shared_ptr<Models::Level> Builder::LevelBuilder::build(std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> level_layers, const std::shared_ptr<Controllers::AudioController> audio_controller)
{
    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = level_layers.first;
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = level_layers.second;
    std::shared_ptr<Models::Level> level = {};

    for (std::pair<int, std::vector<std::vector<int>>> tileset : tiles) {
        _tile_builder.build(level, tileset);
    }

    for (std::vector<std::pair<std::string, std::any>> object : objects) {

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
        level->add_background(_background_factory.create(Enums::TypeEnum::BG, x, y, bg_width, bg_height, 0, Enums::DirectionEnum::NONE));

        y += bg_height;

        while (y <= level->get_height()) {
            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP1, x, y, top_width, top_height, 0, Enums::DirectionEnum::NONE));
            y += top_height;

            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP2, x, y, top_width, top_height, 0, Enums::DirectionEnum::NONE));
            y += top_height;
        }

        y = 0;
        x += bg_width;
    }
}

void Game::Builder::LevelBuilder::build_borders(std::shared_ptr<Game::Models::Level>& level)
{
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0, level->get_height(), 1, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //top
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(0, -1, 1, level->get_width(), false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //bot
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(-1, 0, level->get_height(), 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //lef
    level->add_shape(std::make_shared<PhysicsCollision::Models::Shape>(level->get_width(), 0, level->get_height(), 1, false, false, PhysicsCollision::Enums::ShapeEnum::Square)); //rig
}
