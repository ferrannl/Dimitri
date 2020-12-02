#include "CsvReader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> DocumentHandler::Readers::CsvReader::Read(const std::filesystem::path& path)
{
	std::ifstream file{path};

	std::vector<std::vector<int>> retVal;

	if (!file.is_open()) {
		throw std::runtime_error("could not open file");
	}

	// Helper vars
	std::string line, colname;
	int col;

	// Read the column names
	if (file.good())
	{
		// Extract the first line in the file
		std::getline(file, line);

		// Create a stringstream from line
		std::stringstream ss(line);

		// Extract each column name
		while (std::getline(ss, colname, ',')) {

			// Initialize and add <colname, int vector> pairs to result, columname is pushed to the vector becuase the game levels do not have colnames
			std::vector<int> vector = {};
			vector.push_back(std::stoi(colname));
			retVal.push_back({ vector });
		}
	}


	while (std::getline(file, line)) {
		std::stringstream ss(line);

		int colIndex = 0;

		while (ss >> col) {

			// Add the current integer to the 'colIdx' column's values vector
			retVal.at(colIndex).push_back(col);

			// If the next token is a comma, ignore it and move on
			if (ss.peek() == ',') ss.ignore();

			// Increment the column index
			colIndex++;
		}
	}

	file.close();

	return retVal;
}
