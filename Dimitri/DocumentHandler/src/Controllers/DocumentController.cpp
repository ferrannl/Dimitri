#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Interfaces/IReader.h"
#include "../Readers/CsvReader.h"
#include "../Readers/TiledReader.h"

#include <src/Helpers/BasePathHelper.h>


using namespace DocumentHandler;
namespace fs = std::filesystem;

std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> Controllers::DocumentController::ReadTiledLevel(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".json") {
		Readers::TiledReader reader {};
		return reader.Read(filePath);
	}
}
