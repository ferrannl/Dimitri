#include "TileBuilder.h"
using namespace Game;

void Game::Builder::TileBuilder::build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset)
{
    int level_height = (tileset.second.size()) * TILE_SIZE;
    int level_width = (tileset.second.at(0).size() * TILE_SIZE);

    int x = 0;
    int y = level_height;

    try {
        for (std::vector<int> vector : tileset.second) {
            for (int object : vector) {
                switch (object) {
                case 0:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::FLOOR, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 1:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CORNER, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::LEFT));
                    break;
                case 2:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CORNER, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    break;
                case 3:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::LAMP, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    break;
                case 4:
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::LEVER, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    break;
                case 5:
                    level->add_player(std::make_shared<Models::Player>(x, y, tileset.first, TILE_SIZE * 2, TILE_SIZE * 2, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0,0 }));
                    break;
                case 6:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::WALL, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 43:
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::CAR, x, y, tileset.first, TILE_SIZE * 2, TILE_SIZE * 4, Enums::DirectionEnum::RIGHT));
                    break;
                case 11:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::BEAM, x, y, 0, TILE_SIZE, TILE_SIZE * 5, Enums::DirectionEnum::NONE));
                    break;
                case 47:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::CAM_VISION, x, y, 0, TILE_SIZE, TILE_SIZE * 5, Enums::DirectionEnum::NONE));
                    break;
                case 16:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CAMERA, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 52:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::SPIKE, x, y, 0, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 17:
                    // add enemy
                    break;
                }

                x += TILE_SIZE;
            }

            x = 0;
            y -= TILE_SIZE;
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong during the build phase of the level");
    }
}
