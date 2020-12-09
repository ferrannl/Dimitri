#pragma once
#include <filesystem>
#include <any>
#include <vector>

/**
* \namespace DocumentHandler
* \brief Namespace for the documentHandler
*/
namespace DocumentHandler {
	/**
	* \namespace DocumentHandler.Readers
	* \brief Namespace for the readers
	*/
	namespace Readers {
		/**
		* \class CsvReader
		* \brief Class contains the methods to read an csv file by path
		*/
		class TiledReader {
		public:
			/**
			* \brief Reads the csv file
			*/
			std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> Read(const std::filesystem::path& path);
			std::vector<std::vector<int>> ReadTiles(const std::vector<uint32_t>& tiles, const int& width);
		};
	}
}