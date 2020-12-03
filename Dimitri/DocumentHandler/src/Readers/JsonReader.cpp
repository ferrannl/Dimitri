#include "JsonReader.h"
#include <json/json.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> DocumentHandler::Readers::JsonReader::Read(const std::filesystem::path& path)
{
	std::ifstream json_file(path);

	if (!json_file.is_open()) {
		throw std::runtime_error("Cannot open json file");
	}

	// adding each line to the root string so that the json parser can use it
	std::string raw_json;
	std::string line;
	while (std::getline(json_file, line)) {
		raw_json.append(line);
		std::cout << line.c_str() << std::endl;
	}

	Json::CharReaderBuilder builder;
	const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	const auto rawJsonLength = static_cast<int>(raw_json.length());
	JSONCPP_STRING err;
	Json::Value root;

	if (!reader->parse(raw_json.c_str(), raw_json.c_str() + rawJsonLength, &root,
		&err)) {
		std::cout << "error" << std::endl;
		throw std::runtime_error("Cannot parse json file");
	}

	for (const Json::Value& obj : root["layers"])  // iterate over "books"
	{
		std::cout << obj.asString();
	}


    return std::vector<std::vector<int>>();
}
