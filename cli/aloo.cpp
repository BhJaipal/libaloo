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
			remainingArgs.push_back(std::string(argv[i + 2]));
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
		}
		return 0;
	}
	std::cout << "\n";
	return 0;
}
