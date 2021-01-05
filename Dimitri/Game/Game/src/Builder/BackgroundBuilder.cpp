#include "BackgroundBuilder.h"

void Game::Builder::BackgroundBuilder::build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset, const std::vector<std::vector<std::pair<std::string, std::any>>>& objects)
{
    int x = 0;
    int y = (level->get_height() - TILE_SIZE);

    try {
        for (std::vector<int> vector : tileset.second) {
            for (int object : vector) {
                switch (object) {
                case 1260:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG, x, y, tileset.first, 720, 680, Enums::DirectionEnum::NONE));
                    break;
                case 612:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP1, x, y, tileset.first, 80, 680, Enums::DirectionEnum::NONE));
                    break;
                case 540:
                    level->add_background(_background_factory.create(Enums::TypeEnum::BG_TOP2, x, y, tileset.first, 80, 680, Enums::DirectionEnum::NONE));
                    break;
                }

                x += TILE_SIZE;
            }

            x = 0;
            y -= TILE_SIZE;
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong during the creation phase of the background, make sure it has tilesetid 1");
    }
}
