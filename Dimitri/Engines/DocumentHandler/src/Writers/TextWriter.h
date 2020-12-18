#pragma once
#include <filesystem>
#include "../Interfaces/IWriter.h"

/**
* \namespace DocumentHandler
* \brief Namespace for the documentHandler
*/
namespace DocumentHandler {
	/**
	* \namespace DocumentHandler.Writers
	* \brief Namespace for the Writers
	*/
	namespace Writers {
		/**
		* \class TextWriter
		* \brief Class contains the methods to write to a text file by path
		*/
		class TextWriter : public Interfaces::IWriter {
		public:
			/**
			* \brief Writes to text file
			*/
			void Write(const std::string& path, std::vector<std::vector<std::string>> data);
		};
	}
}