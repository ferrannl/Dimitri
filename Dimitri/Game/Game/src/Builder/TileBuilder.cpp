#include "TileBuilder.h"

using namespace Game;

void Game::Builder::TileBuilder::build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset, const std::vector<std::vector<std::pair<std::string, std::any>>>& objects)
{
    int x = 0;
    int y = (level->get_height() - TILE_SIZE);
    int tiled_y = 0;
    int val1 = 0;
    int val2 = 0;
    bool secret = false;

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
                    secret = get_value<bool>("Rasputin", get_object(objects, x, tiled_y));
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::LEVER, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT, get_lights(get_object(objects, x, tiled_y)), secret));
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
                    val1 = get_value<int>("Lamp_yPos", get_object(objects, x, tiled_y));
                    secret = get_value<bool>("Visible", get_object(objects, x, tiled_y));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::BEAM, x, y, tileset.first, (val1 - y), TILE_SIZE * 5, Enums::DirectionEnum::NONE, 0, secret));
                    break;
                case 47:
                    val1 = get_value<int>("Camera_yPos", get_object(objects, x, tiled_y));
                    val2 = get_value<int>("Rotation_Borders", get_object(objects, x, tiled_y));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::CAM_VISION, x, y, tileset.first, (val1 -y), TILE_SIZE * 5, Enums::DirectionEnum::NONE, val2));
                    break;
                case 16:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CAMERA, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 52:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::SPIKE, x, y, tileset.first, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 1260:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG, x, y, tileset.first, 720, 680, Enums::DirectionEnum::NONE));
                    break;
                case 576:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP1, x, y, tileset.first, 80, 680, Enums::DirectionEnum::NONE));
                    break;
                case 468:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP2, x, y, tileset.first, 80, 680, Enums::DirectionEnum::NONE));
                    break;
                case 17:
                    level->add_enemy(std::make_shared<Models::Enemy>(x, y, 1, TILE_SIZE * 2, TILE_SIZE * 2, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0,0 },
                        get_value<int>("Area_Left", get_object(objects, x, tiled_y)),
                        get_value<int>("Area_Right", get_object(objects, x, tiled_y)),
                        get_value<int>("Area_Top", get_object(objects, x, tiled_y)),
                        get_value<int>("Area_Bottom", get_object(objects, x, tiled_y))
                        ));
                    break;
                }

                x += TILE_SIZE;
            }

            secret = false;
            x = 0;
            y -= TILE_SIZE;
            tiled_y += TILE_SIZE;
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong during the creation phase of the tiles");
    }
}

const std::vector<std::pair<std::string, std::any>> Game::Builder::TileBuilder::get_object(const std::vector<std::vector<std::pair<std::string, std::any>>>& objects, int x, int y)
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

std::vector<std::tuple<float, float>> Game::Builder::TileBuilder::get_lights(const std::vector<std::pair<std::string, std::any>>& object)
{
    std::vector<std::tuple<float, float>> retVal = {};

    for (std::pair<std::string, std::any> val : object) {
        if (val.first.substr(0, 5) == "Light") {
            std::string input = std::any_cast<std::string>(val.second);

            std::size_t comma_pos = input.find(',');
            auto a = input.substr(0, comma_pos);
            auto a2 = input.substr(comma_pos + 1);

            int xpos = stoi(input.substr(0, comma_pos));
            int ypos = stoi(input.substr(comma_pos + 1));


            retVal.push_back(std::make_tuple(xpos, ypos));
        }
    }

    return retVal;
}
