#pragma once
#include <filesystem>
#include "../Interfaces/IReader.h"

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
		class CsvReader : public Interfaces::IReader {
		public:
			/**
			* \brief Reads the csv file
			*/
			std::vector<std::vector<int>> Read(const std::filesystem::path& path);
		}; 
	}
}