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
		* \class TiledReader
		* \brief Class contains the methods to read an tiled json file by path
		*/
		class TiledReader {
		public:
			/**
			* \brief Reads the tiled file
			*/
			std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> Read(const std::filesystem::path& path);

			/**
			* \brief Reads the tiles
			*/
			std::vector<std::vector<int>> ReadTiles(const std::vector<uint32_t>& tiles, int width);
		};
	}
}