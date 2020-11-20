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

namespace DocumentHandler {
	namespace Controllers {
		class DOCUMENT_API DocumentController {
		public:
			std::vector<std::vector<int>> Read(const std::string& path);
		};
	}
}