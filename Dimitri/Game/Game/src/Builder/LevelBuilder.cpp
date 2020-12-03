#include "LevelBuilder.h"

using namespace Game;

std::shared_ptr<Models::Level> Builder::LevelBuilder::build(std::vector<std::vector<int>> objects, const std::shared_ptr<Controllers::AudioController> audio_controller)
{
    int level_height = (objects.at(0).size() - 1) * TILE_SIZE;
    int level_width = (objects.size()) * TILE_SIZE;

    std::shared_ptr<Models::Level> level = std::make_shared<Models::Level>(audio_controller, level_width, level_height );

    int x = 0;
    int y = level_height;

    build_background(level);
    build_borders(level);

    std::vector<std::shared_ptr<Models::Object>> lights = {};

    try {
        for (std::vector<int> vector : objects) {
            for (int object : vector) {
                switch (object) {
                case 0:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::FLOOR, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 1:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CORNER, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::LEFT));
                    break;
                case 2:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CORNER, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    break;
                case 3:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::LAMP, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::BEAM, lights.at(lights.size() - 1)->get_x(), lights.at(lights.size() - 1)->get_y(), 0, (y - lights.at(lights.size() - 1)->get_y()) + 20, TILE_SIZE * 5, Enums::DirectionEnum::RIGHT));
                    break;
                case 4:
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::LEVER, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::RIGHT));
                    break;
                case 5:
                    level->add_player(std::make_shared<Models::Player>(x, y, 1, TILE_SIZE * 2, TILE_SIZE * 2, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0,0 }));
                    break;
                case 6:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::WALL, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 43:
                    level->add_interactable(_interactable_factory.create(Enums::TypeEnum::CAR, x, y, 1, TILE_SIZE * 2, TILE_SIZE * 4, Enums::DirectionEnum::RIGHT));
                    break;
                case 11:
                    lights.push_back(_updatable_factory.create(Enums::TypeEnum::BEAM, x, y, 0, TILE_SIZE, TILE_SIZE * 5, Enums::DirectionEnum::NONE));
                    break;
                case 47:
                    lights.push_back(_updatable_factory.create(Enums::TypeEnum::CAM_VISION, x, y, 0, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 16:
                    level->add_tile(_object_factory.create(Enums::TypeEnum::CAMERA, x, y, 1, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::CAM_VISION, lights.at(lights.size() - 1)->get_x(), lights.at(lights.size() - 1)->get_y(), 0, (y - lights.at(lights.size() - 1)->get_y()) + 20, TILE_SIZE * 5, Enums::DirectionEnum::NONE));
                    break;
                case 52:
                    level->add_updatable(_updatable_factory.create(Enums::TypeEnum::SPIKE, x, y, 0, TILE_SIZE, TILE_SIZE, Enums::DirectionEnum::NONE));
                    break;
                case 17:
                    // add enemy
                    break;
                }

                y -= TILE_SIZE;
            }

            y = level_height;
            x += TILE_SIZE;
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong during the build phase of the level");
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
            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP1, x, y, 0, bg_height, bg_width, Enums::DirectionEnum::NONE));
            y += top_height;

            level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP2, x, y, 0, bg_height, bg_width, Enums::DirectionEnum::NONE));
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
