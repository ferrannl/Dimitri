#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Readers/TiledReader.h"
#include "../Interfaces/IWriter.h"
#include "../Readers/TextReader.h"
#include "../Writers/TextWriter.h"

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

void DocumentHandler::Controllers::DocumentController::Write(const std::string& path, std::vector<std::vector<int>> data)
{
	fs::path filePath = path;

	if (filePath.extension() == ".txt") {
		Writers::TextWriter writer{};
		writer.Write(path, data);
	}
}

std::vector<std::vector<int>> DocumentHandler::Controllers::DocumentController::Read(const std::string& path) {

	fs::path filePath = path;

	if (filePath.extension() == ".txt") {
		Readers::TextReader reader{};
		return reader.Read(filePath);
	}
}
