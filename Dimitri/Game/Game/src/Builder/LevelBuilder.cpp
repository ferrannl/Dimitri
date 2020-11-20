#include "LevelBuilder.h"

using namespace Game;

Game::Builder::LevelBuilder::LevelBuilder() {
    _objectFactory = {};
    _interactableFactory = {};
    _backgroundFactory = {};
}

std::shared_ptr<Game::Models::Level> Builder::LevelBuilder::build(std::vector<std::vector<int>> objects)
{
    std::shared_ptr<Game::Models::Level> level{ new Game::Models::Level };

    int level_height = (objects.at(0).size() - 1) * TILE_SIZE;
    int level_width = (objects.size()) * TILE_SIZE;

    int x = 0;
    int y = level_height;

    build_background(level, level_width, level_height);

    for (std::vector<int> vector : objects) {
        for (int object : vector) {
            switch (object) {
            case 0:
                level->add_object(_objectFactory.create(Game::Enums::TypeEnum::FLOOR, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::StateEnum::HORIZONTAL));
                break;
            case 1:
                level->add_object(_objectFactory.create(Game::Enums::TypeEnum::FLOOR, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::StateEnum::LEFT));
                break;
            case 2:
                level->add_object(_objectFactory.create(Game::Enums::TypeEnum::FLOOR, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::StateEnum::RIGHT));
                break;
            case 3:
                //level->add_object(_objectFactory.create(Game::Enums::TypeEnum::LAMP, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::StateEnum::RIGHT));
                break;
            case 4:
                level->add_interactable(_interactableFactory.create(Game::Enums::TypeEnum::LEVER, x, y, 1, TILE_SIZE, TILE_SIZE));
                break;
            case 5:
                level->add_player(_objectFactory.create(Game::Enums::TypeEnum::PLAYER, x, y, 1, 80, 80, Enums::StateEnum::RIGHT));
                break;
            case 6:
                level->add_object(_objectFactory.create(Game::Enums::TypeEnum::FLOOR, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::StateEnum::VERTICAL));
                break;
            case 43:
                level->add_object(_interactableFactory.create(Game::Enums::TypeEnum::CAR, x, y, 1, 80, 160));
                break;
            }
            y -= TILE_SIZE;
        }

        y = level_height;
        x += TILE_SIZE;
    }

    return level;
}

void Builder::LevelBuilder::build_background(std::shared_ptr<Game::Models::Level>& level, const int width, const int height) {
    int bg_height = 720;
    int bg_width = 680;
    int top_height = 80;
    int top_width = bg_width;

    int x = 0;
    int y = 0;

    while (x < width) {
        level->add_background(_backgroundFactory.create(Enums::TypeEnum::BG, x, y, bg_width, bg_height, 0, Enums::StateEnum::HORIZONTAL));

        y += bg_height;

        while (y <= height) {
            level->add_background(_backgroundFactory.create(Enums::TypeEnum::BG_TOP1, x, y, top_width, top_height, 0, Enums::StateEnum::HORIZONTAL));
            y += top_height;

            level->add_background(_backgroundFactory.create(Enums::TypeEnum::BG_TOP2, x, y, top_width, top_height, 0, Enums::StateEnum::HORIZONTAL));
            y += top_height;
        }

        y = 0;
        x += bg_width;
    }
}