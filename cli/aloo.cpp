#define ALOO_TUI
#include "create-app.cpp"
#include "model.cpp"
#include "utils.cpp"
#include <cstdlib>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	std::string currWD = "/etc/aloo";
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
		for (int i = 0; i < argc; i++) {
			if (i > 1) remainingArgs.push_back(std::string(argv[i]));
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
		} else if (command == "create-app") {
			char **args;
			for (int i = 0; i < argc - 1; i++) {
				strcpy(args[i], remainingArgs[i].c_str());
			}
			create_app(argc - 1, args, currWD);
		} else if (command == "model") {
			char **args;
			for (int i = 0; i < argc - 1; i++) {
				strcpy(args[i], remainingArgs[i].c_str());
			}
			create_app(argc - 1, args, currWD);
		} else if (command == "connect-db") {
			char **args;
			for (int i = 0; i < argc - 1; i++) {
				strcpy(args[i], remainingArgs[i].c_str());
			}
			create_app(argc - 1, args, currWD);
		}
		return 0;
	}
	std::cout << "\n";
	return 0;
}
