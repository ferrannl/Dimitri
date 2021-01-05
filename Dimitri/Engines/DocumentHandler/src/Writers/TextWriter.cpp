#include "TextWriter.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void DocumentHandler::Writers::TextWriter::Write(const std::string& path, std::vector<std::vector<std::string>> data)
{
	//create/open file
	ofstream File(path);

	//add all numbers from data to file
	for (auto vec : data) {
		File << "next\n";
		for (auto num : vec) {
			File << num + "\n";
		}
	}

	//close file
	File.close();
}