#pragma once
#include <string>

namespace Models {
	class __declspec(dllexport) Audio {
	private:
		std::string* _name;
		const char* _path;
	public:
		std::string* get_name();
		const char* get_path();
		Audio(std::string* name, const char* path) : _name{ name }, _path{ path } {};
	};
}