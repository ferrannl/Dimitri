#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Interfaces/IReader.h"
#include "../Readers/CsvReader.h"
#include "../Readers/TiledReader.h"

#include <src/Helpers/BasePathHelper.h>


using namespace DocumentHandler;
namespace fs = std::filesystem;

std::vector<std::vector<int>> Controllers::DocumentController::ReadTiledLevel(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".json") {
		Readers::TiledReader reader {};
		return reader.Read(filePath);
	}
	}
}
