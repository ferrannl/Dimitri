#pragma once

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
		* \class IReader
		* \brief interface contains the method to read an file by path and return an readable memory representatetion
		*/
		class IReader {
		public:
			/**
			* \brief calls the needed reader by file header and returns vector
			*/
			virtual std::vector<std::vector<std::string>> Read(const std::filesystem::path& path) = 0;
		};
	}
}