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
		* \class TextReader
		* \brief Class contains the methods to read an text file by path
		*/
		class TextReader : public Interfaces::IReader {
		public:
			/**
			* \brief Reads the text file
			*/
			std::vector<std::vector<std::string>> Read(const std::filesystem::path& path);
		};
	}
}