#pragma once
#define CURL_STATICLIB
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define UTILITY_API
#endif

namespace Utility{
	namespace Advertisement {
		class advertisement {
		private:
		public:
			UTILITY_API advertisement();
			UTILITY_API void http_download_images(std::string destination, std::string zip_location);
			UTILITY_API void unzip_file(std::string destination, std::string zip_location);
		};
	}
}
