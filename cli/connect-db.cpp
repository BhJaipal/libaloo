#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <string>
#include <vector>

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
	std::string db;
	if (argc >= 2) {
		db = std::string(argv[1]);
		if (!(db == "sqlite3" || db == "mongo")) {
			std::cerr << "Unknown database: " << db;
			return 1;
		}
	} else {
		db = std::string("sqlite3");
		std::cout << "Enter database Type[sqlite3|mongo]: ";
		std::cin >> db;
		if (!(db == "sqlite3" || db == "mongo")) {
			std::cerr << "Unknown database: " << db;
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
					if (!ends_with(dbname, ".db") &&
						!ends_with(dbname, ".sqlite")) {
						throw std::runtime_error(
							"Database file must end with .db or .sqlite");
					}
				} else {
					dbname = argv[3];
					if (!ends_with(dbname, ".db") &&
						!ends_with(dbname, ".sqlite")) {
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
				alooJson["db"] = dbJson;
				std::cout << alooJson["db"] << std::endl;
				std::ofstream alooRes("aloo.json", std::ofstream::binary);
				alooRes << alooJson;
			} else if (sqliteArgs == "restart") {
				std::ifstream people_file("aloo.json", std::ifstream::binary);
				Json::Value alooJson;
				people_file >> alooJson;
				std::cout << alooJson["db"] << std::endl;
				std::string dbname = alooJson["db"].asCString();
				FILE *dbFile = fopen(dbname.c_str(), "w");
				fprintf(dbFile, "");
			} else if (sqliteArgs == "add") {
				std::ifstream people_file("aloo.json", std::ifstream::binary);
				Json::Value alooJson;
				people_file >> alooJson;
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
					std::cerr << "Model not found" << std::endl;
					return 1;
				}
				// std::cout << outModel << std::endl;
				std::string currentPath = argv[0];
				int matchIndex = -1, startI;
				found = 0;
				int currI = 0;
				std::string currFileName = "con";
				std::vector<std::string> tokens =
					split(currentPath, currFileName);
				std::string path = currentPath.substr(0, startI);
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