#pragma once
#include <vector>
#include <filesystem>

/**
* \namespace DocumentHandler
* \brief Namespace for the documentHandler
*/
namespace DocumentHandler {
	/**
	* \namespace DocumentHandler.Interfaces
	* \brief Namespace for the interfaces
	*/
	namespace Interfaces {
		/**
		* \class IWriter
		* \brief interface contains the method to write to a file by path
		*/
		class IWriter {
		public:
			/**
			* \brief calls the needed writer and writes the data to the file
			*/
			virtual void Write(const std::string& path, std::vector<std::vector<int>>) = 0;
		};
	}
}