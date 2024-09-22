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

bool con_ends_with(std::string const &fullString, std::string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(),
										ending.length(), ending));
	} else {
		return false;
	}
}

std::vector<std::string> con_split(const std::string &str,
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

int connect_db(int argc, char const *argv[], std::string currWD) {
	int status;
	std::string db;
	if (argc >= 2) {
		db = std::string(argv[1]);
		if (!(db == "sqlite3" || db == "mongo")) {
			throw std::runtime_error("Unknown database: " + db);
			return 1;
		}
	} else {
		db = std::string("sqlite3");
		std::cout << "Enter database Type[sqlite3|mongo]: ";
		std::cin >> db;
		if (!(db == "sqlite3" || db == "mongo")) {
			throw std::runtime_error("Unknown database: " + db);
			return 1;
		}
	}

	if (db == "sqlite3") {
		if (argc >= 3) {
			std::string sqliteArgs = argv[2];
			if (sqliteArgs == "new") {
				std::string dbname;
				if (argc < 4) {
					std::cout << "Enter database name: ";
					std::cin >> dbname;
					if (!con_ends_with(dbname, ".db") &&
						!con_ends_with(dbname, ".sqlite")) {
						throw std::runtime_error(
							"Database file must end with .db or .sqlite");
					}
				} else {
					dbname = argv[3];
					if (!con_ends_with(dbname, ".db") &&
						!con_ends_with(dbname, ".sqlite")) {
						throw std::runtime_error(
							"Database file must end with .db or .sqlite");
					}
				}
				FILE *dbFile = fopen(dbname.c_str(), "w");
				fprintf(dbFile, "");
				std::ifstream people_file("aloo.json", std::ifstream::binary);
				Json::Value alooJson;
				people_file >> alooJson;
				Json::Value dbJson = Json::Value(dbname.c_str());
				alooJson["sqlite-db"] = dbJson;
				std::ofstream alooRes("aloo.json", std::ofstream::binary);
				alooRes << alooJson;
			} else if (sqliteArgs == "restart") {
				std::ifstream alooJsonFile("aloo.json", std::ifstream::binary);
				Json::Value alooJson;
				alooJsonFile >> alooJson;
				std::string dbname = alooJson["sqlite-db"].asCString();
				FILE *dbFile = fopen(dbname.c_str(), "w");
				fprintf(dbFile, "");
			} else if (sqliteArgs == "add") {
				std::ifstream alooJsonFile("aloo.json", std::ifstream::binary);
				Json::Value alooJson;
				alooJsonFile >> alooJson;
				std::string modelName;
				if (argc >= 4) {
					modelName = argv[3];
				} else {
					std::cout << "Enter model name: ";
					std::cin >> modelName;
				}
				Json::Value models = alooJson["models"];
				int found = 0;
				Json::Value outModel;
				for (Json::Value::iterator i = models.begin();
					 i != models.end(); i++) {
					Json::Value model = *i;
					if (std::string(model["modelName"].asCString()) ==
						modelName) {
						found = 1;
						outModel = model;
						break;
					}
				}
				if (!found) {
					throw std::runtime_error("Model not found\n");
					return 1;
				}
				std::string currentPath = argv[0];
				int matchIndex = -1, startI;
				found = 0;
				int currI = 0;

				std::vector<std::string> curr = con_split(argv[0], "bin");
				std::string serverPath = curr[0] + "cli/sample/main.server.";
				std::ifstream serverHeader((serverPath + "c").c_str());
				if (!serverHeader.is_open()) {
					throw std::runtime_error(
						"Failed to open sample server file");
				}
				if (!std::filesystem::exists("server"))
					std::filesystem::create_directories("server");
				if (std::filesystem::exists("server/" + modelName + ".c")) {
					throw std::runtime_error(
						"Server Source file already exists");
				}
				if (std::filesystem::exists("server/" + modelName + ".h")) {
					throw std::runtime_error(
						"Server Header file already exists");
				}
				std::string line;
				std::string content = "";
				std::string body = "ID INTEGER PRIMARY KEY AUTOINCREMENT, ";
				std::string colNames = "";
				std::string members = "val.id = values[i++];\n\t";
				std::string colArr = "\"";
				int colCount = 0;
				for (Json::Value::iterator i = outModel["members"].begin();
					 i != outModel["members"].end(); i++) {
					Json::Value mem = *i;
					colNames += mem["member"].asCString();
					if (std::string(mem["type"].asCString()) == "string") {
						members += "strcpy(val." +
								   std::string(mem["member"].asCString()) +
								   ", values[i++]);\n\t";
					} else {
						members += "val.";
						members += mem["member"].asCString();
						members += " = values[i++];\n\t";
					}
					colNames += ", ";
					colArr += mem["member"].asCString();
					colArr += "\", \"";
					body += mem["member"].asCString();
					body += " ";
					body += typeSwitch[mem["type"].asCString()];
					body += ", ";
					colCount++;
				}
				members.resize(members.size() - 2);
				colNames.resize(colNames.size() - 2);
				colArr.resize(colArr.size() - 3);
				body.resize(body.size() - 2);
				while (getline(serverHeader, line)) {
					while (line.find("$modelName") != std::string::npos) {
						line.replace(line.find("$modelName"),
									 std::string("$modelName").size(),
									 modelName);
					}
					if (line.find("$body") != std::string::npos) {
						line.replace(line.find("$body"),
									 std::string("$body").size(), body);
					}
					if (line.find("$cols$") != std::string::npos) {
						line.replace(line.find("$cols$"),
									 std::string("$cols$").size(), colArr);
					}
					if (line.find("$col_count") != std::string::npos) {
						line.replace(line.find("$col_count"),
									 std::string("$col_count").size(),
									 std::to_string(colCount));
					}
					if (line.find("$cols") != std::string::npos) {
						line.replace(line.find("$cols"),
									 std::string("$cols").size(), colNames);
					}
					if (line.find("val.$member = values[i++];") !=
						std::string::npos) {
						line.replace(
							line.find("val.$member = values[i++];"),
							std::string("val.$member = values[i++];").size(),
							members);
					}
					content += line + '\n';
				}
				std::ofstream serverFile("server/" + modelName + ".c");
				serverFile << content;
				serverFile.close();
				serverHeader.close();

				serverHeader = std::ifstream((serverPath + "h").c_str());
				if (!serverHeader.is_open()) {
					throw std::runtime_error(
						"Failed to open sample server file");
				}
				content = "";
				line = "";
				while (getline(serverHeader, line)) {
					while (line.find("$modelName") != std::string::npos) {
						line.replace(line.find("$modelName"),
									 std::string("$modelName").size(),
									 modelName);
					}
					content += line + '\n';
				}
				serverFile = std::ofstream("server/" + modelName + ".h");
				serverFile << content;
				serverFile.close();
				serverHeader.close();
			}
		} else {
			std::cout << "Requires one more arguments:\n";
			std::cout << "\tnew <dbname>\t\tCreates new database files\n";
			std::cout << "\tadd <model>\t\tCreates new server setup for ";
			std::cout << "connection with model and database\n";
		}
	} else {
		std::cout << "Not implemented yet";
	}
	std::cout << "\n";

	return 0;
}
