#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Interfaces/IReader.h"
#include "../Readers/CsvReader.h"
using namespace DocumentHandler;
namespace fs = std::filesystem;

std::vector<std::vector<int>> Controllers::DocumentController::Read(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".csv") {
		Readers::CsvReader reader {};
		return reader.Read(filePath);
	}


}
