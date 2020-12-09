#include "TiledReader.h"
#include "../Tileson/tileson.hpp"
#include "CsvReader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<std::pair<std::string, std::any>>>> DocumentHandler::Readers::TiledReader::Read(const std::filesystem::path& path)
{
	tson::Tileson parser;
    std::unique_ptr<tson::Map> map;

    try {
        map = parser.parse(path);

        if (map->getStatus() != tson::ParseStatus::OK) {
            throw std::exception();
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong parsing the level file");
    }

    std::pair<std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> _retVal = {};
    std::vector<std::vector<std::vector<int>>> tiles = {};
    std::vector<std::vector<std::pair<std::string, std::any>>> objects;

    for (auto& layer : map->getLayers())
    {
        if (layer.getType() == tson::LayerType::TileLayer) {
            std::map<std::tuple<int, int>, tson::Tile*> tileData = layer->getTileData();
            tiles.push_back(Readers::CsvReader::Read(path));
        }
        else if (layer.getType() == tson::LayerType::ObjectGroup)
        {
            for (auto& obj : layer.getObjects())
            {
                std::vector<std::pair<std::string, std::any>> _obj = {};
                _obj.push_back({ "id", obj.getId() });
                _obj.push_back({ "type", obj.getType() });
                _obj.push_back({ "name", obj.getName() });
                _obj.push_back({ "position", obj.getPosition() });

                for (std::pair<std::string, tson::Property> prop : obj.getProperties().getProperties()) {
                    _obj.push_back({ prop.first, prop.second.getValue() });
                }

                objects.push_back(_obj);
            }
        }
    }

    _retVal.first = tiles;
    _retVal.second = objects;

    return _retVal;
}
