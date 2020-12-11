#include "TileBuilder.h"
using namespace Game;

void Game::Builder::TileBuilder::build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset, const std::vector<std::vector<std::pair<std::string, std::any>>>& objects)
{
    int level_height = (tileset.second.size() - 1) * TILE_SIZE;
    int level_width = (tileset.second.at(0).size() - 1) * TILE_SIZE;

    int x = 0;
    int y = level_height;
    int tiled_y = 0;
    int cam_y = 0;
    int light_y = 0;
    int light_x = 0;
    int rotation_bounds = 0;

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
                    light_y = get_value<int>("Light_yPos", get_object(objects, x, tiled_y));
                    light_x = get_value<int>("Light_xPos", get_object(objects, x, tiled_y));
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::LEVER, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT, light_x, light_y));
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
                    light_y = get_value<int>("Lamp_yPos", get_object(objects, x, tiled_y));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::BEAM, x, y, tileset.first, (light_y - y), TILE_SIZE * 5, Enums::DirectionEnum::NONE));
                    break;
                case 47:
                    cam_y = get_value<int>("Camera_yPos", get_object(objects, x, tiled_y));
                    rotation_bounds = get_value<int>("Rotation_Borders", get_object(objects, x, tiled_y));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::CAM_VISION, x, y, tileset.first, (cam_y-y), TILE_SIZE * 5, Enums::DirectionEnum::NONE, rotation_bounds));
                    break;
                case 16:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CAMERA, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 52:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::SPIKE, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 17:
                    // add enemy
                    break;
                }

                x += TILE_SIZE;
            }

            x = 0;
            y -= TILE_SIZE;
            tiled_y += TILE_SIZE;
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong during the creation phase of the tiles");
    }
}

const std::vector<std::pair<std::string, std::any>> Game::Builder::TileBuilder::get_object(const std::vector<std::vector<std::pair<std::string, std::any>>>& objects, const int x, const int y)
{
    if (objects.size() == 0) {
        return std::vector<std::pair<std::string, std::any>>{ {"empty", "0"} };
    }

    for (std::vector<std::pair<std::string, std::any>> object : objects) {
        for (std::pair<std::string, std::any> value : object) {
            if (value.first._Equal("position")) {
                std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                if (std::get<0>(position) == x && std::get<1>(position) == y) {
                    return object;
                }
            }
        }
    }

    return std::vector<std::pair<std::string, std::any>>{ {"empty", "0"} };
}
