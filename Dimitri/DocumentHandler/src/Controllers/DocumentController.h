#pragma once
#include <string>
#include <vector>

#ifdef _WIN64
#ifdef DOCUMENTHANDLER_EXPORTS
#define DOCUMENT_API __declspec(dllexport)
#else 
#define DOCUMENT_API __declspec(dllimport)
#endif
#else
#define DOCUMENT_API
#endif

/**
* \namespace DocumentHandler
* \brief Namespace for the documentHandler
*/
namespace DocumentHandler {
	/**
	* \namespace DocumentHandler.Controllers
	* \brief Namespace for the documentHandler
	*/
	namespace Controllers {
		/**
		* \class DocumentController
		* \brief Class contains the methods to read an file by path
		*/
		class DOCUMENT_API DocumentController {
		public:
			std::vector<std::vector<int>> ReadTiledLevel(const std::string& path);
		};
	}
}