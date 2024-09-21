#include <filesystem>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include <vector>

namespace fs = std::filesystem;
std::string currFileName = "model";

bool ends_with(std::string const &fullString, std::string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(),
										ending.length(), ending));
	} else {
		return false;
	}
}

std::vector<std::string> split(const std::string &str,
							   const std::string &delimiter) {
	std::vector<std::string> tokens;
	std::size_t pos = 0;
	std::size_t found = str.find(delimiter);

	while (found != std::string::npos) {
		tokens.push_back(str.substr(pos, found - pos));
		pos = found + delimiter.length();
		found = str.find(delimiter, pos);
	}

	tokens.push_back(str.substr(pos));
	return tokens;
}

int main(int argc, char const *argv[]) {
	std::string projectPath = "";
	std::string projectName = "";
	if (argc >= 2) {
		if (std::string(argv[1]) == "--name" || std::string(argv[1]) == "-n")
			if (argc == 2) throw std::runtime_error("No name is provided");
			else projectName = argv[2];
		if (std::string(argv[1]) == "--path" || std::string(argv[1]) == "-p")
			if (argc == 2)
				throw std::runtime_error("Project path is not provided");
			else projectPath = argv[2];

		if (projectPath != "") projectPath += "/";
	}
	return 0;
}