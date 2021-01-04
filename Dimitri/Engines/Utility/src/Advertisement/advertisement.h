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

/**
* \namespace Utility
* \brief Namespace for the utility project
*/
namespace Utility{
	/**
	* \namespace Advertisement
	* \brief Namespace for the advertisement in the utility project
	*/
	namespace Advertisement {
		/**
		* \class Advertisement
		* \brief Class contains the the methods to retreive the advertisement images
		*/
		class UTILITY_API advertisement {
		private:
		public:
			 advertisement();
			 /**
			 * /brief Deletes all the advertisement images before adding them
			 */
			 void delete_images(const std::string& destination);
			 /**
			 * /brief Downloads the images from DropBox
			 */
			 void http_download_images(const std::string& destination, const std::string& zip_location);
			 /**
			 * /brief Unzips the files retreived from DropBox
			 */
			 void unzip_file(const std::string& destination, const std::string& zip_location);
		};
	}
}
