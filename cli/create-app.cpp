#pragma once
#include "utils.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include <vector>
namespace fs = std::filesystem;

std::vector<std::string> CAsplit(const std::string &str,
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

int create_app(int argc, std::vector<std::string> argv, std::string currWD) {
	std::string projectPath = "";
	std::string projectName = "";
	char wantDesc;
	std::string appName = "";
	if (argc >= 2) {
		if (argv[1] == "--name" || argv[1] == "-n")
			if (argc == 2) throw std::runtime_error("No name is provided");
			else projectName = argv[2];
		if (argv[1] == "--path" || argv[1] == "-p")
			if (argc == 2)
				throw std::runtime_error("Project path is not provided");
			else projectPath = argv[2];
	} else {
		std::cout << "Enter project name[aloo-project]: ";
		getline(std::cin, projectName);
		if (projectName.empty()) projectName = "aloo-project";
	}

	if (projectPath != "") {
		if (projectPath == ".") {
			std::string path = fs::current_path().string();
			std::vector<std::string> pathName = CAsplit(path, "/");
			projectPath = pathName[pathName.size() - 1];
		}
		std::vector<std::string> pathTokens = CAsplit(projectPath, "/");
		if (pathTokens[pathTokens.size() - 1] == ".")
			projectName = pathTokens[pathTokens.size() - 2];
		projectName = pathTokens[pathTokens.size() - 1];
	}

	std::cout << "Enter app name[Example App]: ";
	getline(std::cin, appName);
	appName = (appName.empty() ? "Example App" : appName);
	if (*appName.end() == '\n') appName.pop_back();

	std::string desc;
	std::cout << "Enter description[An default template for aloo App]: ";
	getline(std::cin, desc);
	desc = (desc.empty() ? "An default template for aloo App" : desc);
	if (*desc.end() == '\n') desc.pop_back();

	std::string currPath;
	if (projectPath != "") {
		if (projectPath[projectPath.size() - 1] != '/') projectPath += "/";
		if (projectPath[0] != '/') projectPath = "/" + projectPath;
		currPath = fs::current_path().string() + projectPath;
	} else {
		fs::create_directory(projectName);
		if (*fs::current_path().string().end() != '/')
			currPath = fs::current_path().string() + "/" + projectName + "/";
		else currPath = fs::current_path().string() + projectName + "/";
	}
	// app dir while beingScoped
	{
		// creating app/ dir
		fs::create_directory(currPath + "app");
		// sample/main.c => app/main.c
		std::ifstream alooSampleApp(currWD + "/sample/main.c",
									std::ifstream::binary);
		std::string appMainC;
		std::string out;
		while (getline(alooSampleApp, out)) appMainC += out + "\n";
		if (appMainC.find("$appName") != std::string::npos)
			appMainC.replace(appMainC.find("$appName"), 8, appName);
		if (appMainC.find("$project") != std::string::npos)
			appMainC.replace(appMainC.find("$project"), 8, projectName);

		std::ofstream alooMainCFile(currPath + "app/main.c",
									std::ofstream::binary);
		alooMainCFile << appMainC;
		alooSampleApp.close();
		alooMainCFile.close();
	}
	// app dir while beingScoped
	{
		// creating test/ dir
		fs::create_directory(currPath + "test");
		// sample/main.c => test/main.c
		std::ifstream alooMainApp(currWD + "/sample/test.c",
								  std::ifstream::binary);
		std::string testMainC;
		std::string out;
		while (getline(alooMainApp, out)) testMainC += out + "\n";
		alooMainApp.close();
		testMainC.replace(testMainC.find("$appName"), 8, appName);
		testMainC.replace(testMainC.find("$project"), 8, projectName);

		std::ofstream appMainCFile(currPath + "test/main.c",
								   std::ofstream::binary);
		appMainCFile << testMainC;
		appMainCFile.close();
	}

	Json::Value alooJson;
	std::ofstream alooJsonFile(currPath + "aloo.json", std::ofstream::binary);
	alooJson["$schema"] = currWD + "/aloo.schema.json";
	alooJson["app"] = appName;
	alooJson["project"] = projectName;
	alooJson["description"] = desc;
	alooJsonFile << alooJson;
	alooJsonFile.close();

	std::ifstream sampleCMake(currWD + "/sample/CMakeLists.txt",
							  std::ifstream::binary);
	std::string cmake;
	std::string out;
	while (getline(sampleCMake, out)) cmake += out + "\n";
	sampleCMake.close();
	cmake.replace(cmake.find("${appName}"), 8, appName);
	cmake.replace(cmake.find("${libaloo}"), 10, currWD + "/lib/libaloo.a");
	cmake.replace(cmake.find("${libaloo}"), 10, currWD + "/lib/libaloo.a");
	cmake.replace(cmake.find("${include_dir}"), 14, currWD + "/include");
	std::ofstream cmakeFile(currPath + "CMakeLists.txt", std::ofstream::binary);
	cmakeFile << cmake;
	cmakeFile.close();
	std::cout << "'" << appName
			  << "' template app created successfully \033[32m\033[0m\n";
	return 0;
}