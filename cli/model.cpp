#include <filesystem>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include <vector>

std::map<std::string, std::string> typeSwitch{
	{"int", "INTEGER"},
	{"string", "TEXT"},
	{"float", "FLOAT"},
	{"bool", "INTEGER"},
};
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
	int status;
	std::string newModelName;
	if (argc >= 2) {
		newModelName = std::string(argv[1]);
	} else {
		std::cout << "Enter model name: ";
		std::cin >> newModelName;
	}

	if (argc >= 3) {
		if (!std::filesystem::exists(("models"))) {
			std::filesystem::create_directory("models");
		}
		if (std::filesystem::exists(("models/" + newModelName + ".h"))) {
			throw std::runtime_error("Model header file already exists");
		}
		std::ifstream alooJsonFile("aloo.json", std::ifstream::binary);
		Json::Value alooJson;
		alooJsonFile >> alooJson;
		alooJsonFile.close();
		Json::Value models = alooJson["models"];
		if (models == Json::Value::null) {
			std::ofstream alooJsonFile("aloo.json", std::ofstream::binary);
			Json::Value arr = Json::arrayValue;
			alooJson["models"] = arr;
			alooJsonFile << alooJson;
			alooJsonFile.close();
			models = alooJson["models"];
		}
		if (models.size()) {
			int found = 0;
			Json::Value outModel;
			for (Json::Value::iterator i = models.begin(); i != models.end();
				 i++) {
				Json::Value model = *i;
				if (std::string(model["modelName"].asCString()) ==
					newModelName) {
					found = 1;
					outModel = model;
					break;
				}
			}
			if (found) {
				throw std::runtime_error("Model already exists");
				return 1;
			}
		}
		Json::Value newModelObj;
		newModelObj["modelName"] = newModelName;
		newModelObj["members"] = Json::arrayValue;
		std::vector<std::string> validTypes{"int", "string", "float", "bool"};
		std::map<std::string, std::string> typeSwitch{
			{"int", "int"},
			{"string", "char*"},
			{"float", "float"},
			{"bool", "_Bool"},
		};
		std::vector<Json::Value> tokens;
		for (int i = 2; i < argc; i++) {
			Json::Value token;
			std::vector<std::string> tokenSplit = split(argv[i], ":");
			int found = 0;
			for (int j = 0; j < 4; j++) {
				if (tokenSplit[1] == validTypes[j]) found = 1;
			}
			if (!found) {
				throw std::runtime_error("Invalid type: " + tokenSplit[1]);
			}

			token["member"] = tokenSplit[0];
			token["type"] = tokenSplit[1];
			tokens.push_back(token);
		}
		for (auto j = tokens.begin(); j != tokens.end(); j++) {
			newModelObj["members"].append(*j);
		}

		std::ofstream alooJsonFileWrite("aloo.json", std::ofstream::binary);
		Json::Value arr = Json::arrayValue;
		arr.append(newModelObj);
		alooJson["models"] = arr;
		alooJsonFileWrite << alooJson;
		alooJsonFileWrite.close();
		std::string modelTemplate =
			"#include \"aloo.h\"\n#include <stdbool.h>\n\ntypedef struct _" +
			newModelName + " {\n\tint id;";
		for (auto i = tokens.begin(); i != tokens.end(); i++) {
			modelTemplate += "\n\t" +
							 typeSwitch[std::string((*i)["type"].asCString())] +
							 " " + (*i)["member"].asCString() + ";";
		}
		modelTemplate += "\n} " + newModelName + ";\n\n";
		std::ofstream modelFile("models/" + newModelName + ".h");
		modelFile << modelTemplate;
		modelFile.close();
	} else {
		throw std::runtime_error("Model must have atleast 1 property");
	}
	return 0;
}