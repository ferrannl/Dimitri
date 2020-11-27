#pragma once
#define CURL_STATICLIB
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <functional>
#include "unzip.h"

class advertisement {
private:
public:
	advertisement();
	void http_download_images(std::string destination, std::string zip_location);
	void unzip_file(std::string destination, std::string zip_location);
};