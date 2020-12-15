#pragma once
#include <string>
#include <vector>
#include <any>

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
			std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> ReadTiledLevel(const std::string& path);
		};
	}
}