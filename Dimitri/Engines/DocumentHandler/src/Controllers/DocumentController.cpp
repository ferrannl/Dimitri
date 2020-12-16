#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Readers/TiledReader.h"

using namespace DocumentHandler;
namespace fs = std::filesystem;

std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> Controllers::DocumentController::ReadTiledLevel(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".json") {
		Readers::TiledReader reader {};
		return reader.Read(filePath);
	}
	else {
		throw std::exception("Only tiled Json files are supported");
	}
}
