#include "LevelBuilder.h"
using namespace Game;

Game::Builder::LevelBuilder::LevelBuilder(const int width, const int height) : _width{ width }, _height{ height } {}

std::shared_ptr<Game::Models::Level> Builder::LevelBuilder::Build(std::vector<std::vector<int>> objects)
{
    std::shared_ptr<Game::Models::Level> level{ new Game::Models::Level };

    int max_height = (objects.at(0).size() - 1) * 40;
    int x = 0;
    int y = max_height;

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
            }
            y -= TILE_SIZE;
        }

        y = max_height;
        x += TILE_SIZE;
    }

    return level;
}