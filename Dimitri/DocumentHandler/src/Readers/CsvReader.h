#pragma once
#include <filesystem>
#include "../Interfaces/IReader.h"

namespace DocumentHandler {
	namespace Readers {
		class CsvReader : public Interfaces::IReader {
		public:
			std::vector<std::vector<int>> Read(const std::filesystem::path& path);
		}; 
	}
}