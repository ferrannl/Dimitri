#include "TextReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

std::vector<std::vector<int>> DocumentHandler::Readers::TextReader::Read(const std::filesystem::path& path)
{
	std::vector<std::vector<int>> result;

	// Create a text string, which is used to output the text file
	string output;

	// Read from the text file
	ifstream file(path);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(file, output)) {
		// Output the text from the file
		cout << output;
		if (output == "next") {
			result.push_back(std::vector<int>());
		}
		else {
			result.back().push_back(stoi(output));
		}
	}

	file.close();

	return result;
}
