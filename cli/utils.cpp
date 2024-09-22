#pragma once
#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;

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

static std::string &implode(const std::vector<std::string> &elems, char delim,
							std::string &s) {
	for (std::vector<std::string>::const_iterator ii = elems.begin();
		 ii != elems.end(); ++ii) {
		s += (*ii);
		if (ii + 1 != elems.end()) { s += delim; }
	}

	return s;
}

static std::string implode(const std::vector<std::string> &elems, char delim) {
	std::string s;
	return implode(elems, delim, s);
}