#pragma once
#define CURL_STATICLIB
#include <curl/curl.h>
#include "../Helpers/BasePathHelper.h"
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
	size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);
	void http_download_images();
	void unzip_file();
};