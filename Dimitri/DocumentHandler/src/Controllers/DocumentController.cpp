#include "DocumentController.h"
#include <filesystem>
#include <fstream>
#include "../Interfaces/IReader.h"
#include "../Interfaces/IWriter.h"
#include "../Readers/CsvReader.h"
#include "../Readers/TextReader.h"
#include "../Writers/TextWriter.h"
#include <src/Helpers/BasePathHelper.h>


using namespace DocumentHandler;
namespace fs = std::filesystem;

std::vector<std::vector<int>> Controllers::DocumentController::Read(const std::string& path)
{
	fs::path filePath = path;

	if (filePath.extension() == ".csv") {
		Readers::CsvReader reader {};
		return reader.Read(filePath);
	}

	if (filePath.extension() == ".txt") {
		Readers::TextReader reader{};
		return reader.Read(filePath);
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
