#define ALOO_TUI
#include "connect-db.cpp"
#include "create-app.cpp"
#include "model.cpp"
#include "utils.cpp"
#include <cstdlib>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	std::string currWD = "$pwd$";
	std::vector<std::string> remainingArgs;
	remainingArgs.push_back(std::string(argv[0]));
	if (argc == 1) {
		help();
	} else {
		std::string command = argv[1];
		if (command == "--help" || command == "-h" || command == "help") {
			help();
			return 0;
		}
		for (int i = 2; i < argc; i++) {
			remainingArgs.push_back(std::string(argv[i]));
		}
		if (command == "build") {
			{
				int _ = std::system(
					(currWD + "/build.sh " + implode(remainingArgs, ' '))
						.c_str());
			}
		} else if (command == "run") {
			int _ = std::system(
				(currWD + "/run.sh " + implode(remainingArgs, ' ')).c_str());
		} else if (command == "clean") {
			{
				int _ = std::system(
					(currWD + "/clean.sh " + implode(remainingArgs, ' '))
						.c_str());
			}
		} else if (command == "model") {
			model(argc - 1, remainingArgs, currWD);
		} else if (command == "create-app") {
			create_app(argc - 1, remainingArgs, currWD);
		} else if (command == "connect-db") {
			connect_db(argc - 1, remainingArgs, currWD);
		}
		return 0;
	}
	std::cout << "\n";
	return 0;
}
