#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Interfaces/IReader.h"
#include "../Readers/CsvReader.h"
#include "../Readers/JsonReader.h"

#include <src/Helpers/BasePathHelper.h>


using namespace DocumentHandler;
namespace fs = std::filesystem;

std::vector<std::vector<int>> Controllers::DocumentController::Read(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".csv") {
		Readers::CsvReader reader {};
		return reader.Read(filePath);
	} else 	if (filePath.extension() == ".json") {
		Readers::JsonReader reader{};
		return reader.Read(filePath);
	}
}
