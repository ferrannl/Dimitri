#define CURL_STATICLIB
#include "advertisement.h"
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

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void advertisement::http_download_images()
{
    CURL* curl;
    FILE* fp;

    std::string destination = Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement/advertisement.zip"};

    fp = fopen(destination.c_str(), "wb");

    curl = curl_easy_init();

    /* A long parameter set to 1 tells the library to follow any Location: header
     * that the server sends as part of an HTTP header in a 3xx response. The
     *Location: header can specify a relative or an absolute URL to follow.
    */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    curl_easy_setopt(curl, CURLOPT_URL, "https://www.dropbox.com/sh/f088zaomi0qpklr/AABDGOMxk76zzn9x2NOHRmDca?dl=1"); // "dl=0"changed to "dl=1" to force download

    // disabe the SSL peer certificate verification allowing the program to download the file from dropbox shared link
    // in case it is not used it displays an error message stating "SSL peer certificate or SSH remote key was not OK"
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    CURLcode res;

    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    fclose(fp);

    unzip_file();

    if (res == CURLE_OK)
        std::cout << "OK";
    else
        std::cout << curl_easy_strerror(res);
}

void advertisement::unzip_file()
{
    TCHAR destination = (TCHAR)(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement/advertisement.zip" }).c_str();
    HZIP hz = OpenZip(_T("" + destination), 0);
    TCHAR zip = (TCHAR)(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" }).c_str();
    SetUnzipBaseDir(hz, _T("" + zip));
    ZIPENTRY ze; GetZipItem(hz, -1, &ze); int numitems = ze.index;
    for (int zi = 0; zi < numitems; zi++)
    {
        GetZipItem(hz, zi, &ze);
        UnzipItem(hz, zi, ze.name);
    }
    CloseZip(hz);
}
