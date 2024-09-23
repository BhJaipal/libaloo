#define ALOO_TUI
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
		for (int i = 0; i < argc; i++) {
			remainingArgs.push_back(std::string(argv[i + 2]));
		}
		if (command == "build") {
			std::system(
				(currWD + "/cli/build.sh " + implode(remainingArgs, ' '))
					.c_str());
		} else if (command == "run") {
			std::system((currWD + "/cli/run.sh " + implode(remainingArgs, ' '))
							.c_str());
		} else if (command == "clean") {
			std::system(
				(currWD + "/cli/clean.sh " + implode(remainingArgs, ' '))
					.c_str());
		}
		return 0;
	}
	std::cout << "\n";
	return 0;
}
