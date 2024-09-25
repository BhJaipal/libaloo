#pragma once
#include "utils.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief Create a app template project
 *
 * @param argc remaining no of arguments except model
 * @param argv remaining vector of arguments except model
 *
 * `aloo model human name:string age:int` creates a new model human struct with
 *`char* name` and `int age` in model/human.h
 * @param currWD path where aloo project related files stays
 */
int model(int argc, std::vector<std::string> argv, std::string currWD) {
	int status;
	std::string newModelName;
	if (argc >= 2) {
		newModelName = argv[1];
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
			std::vector<std::string> token_split =
				split(std::string(argv[i]), ":");
			int found = 0;
			for (int j = 0; j < 4; j++) {
				if (token_split[1] == validTypes[j]) found = 1;
			}
			if (!found) {
				throw std::runtime_error("Invalid type: " + token_split[1]);
			}

			token["member"] = token_split[0];
			token["type"] = token_split[1];
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