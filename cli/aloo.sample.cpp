#include "create-app.cpp"
#include "model.cpp"
#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/direction.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/box.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/color_info.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

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

void help() {
	int cols = 80;
	int lines = 24;

#ifdef TIOCGSIZE
	struct ttysize ts;
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	cols = ts.ts_cols;
	lines = ts.ts_lines;
#elif defined(TIOCGWINSZ)
	struct winsize ts;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
	cols = ts.ws_col;
	lines = ts.ws_row;
#endif /* TIOCGSIZE */

	std::cout << "\033[2;36m";
	std::string tab;
	for (int i = 0; i < 8; i++) { std::cout << "    "; }

	using namespace ftxui;

	Element document = hbox({
		text("left") | border,
		text("middle") | border | flex,
		text("right") | border,
	});

	auto screen = Screen::Create(Dimension::Full(),		  // Width
								 Dimension::Fit(document) // Height
	);
	Render(screen, document);
	screen.Print();
	;
	std::cout << "ALOO CLI";
	for (int i = 0; i < 20; i++) { std::cout << "    "; }
	std::cout << "\nCommands\n";
	std::cout << "\t\taloo create-app <name>\t\t\t\t\t\tCreates "
				 "C Aloo app template\n";
	std::cout << "\t\taloo run [ app | test ]\t\t\t\t\t\tRuns "
				 "Aloo app/ test build\n";
	std::cout << "\t\taloo build\t\t\t\t\t\t\t\tBuilds Aloo "
				 "app/ tests\n";
	std::cout << "\t\taloo clean\t\t\t\t\t\t\t\tRemoves "
				 "previous build data and executables\n";
	std::cout << "Utilities\n";
	std::cout << "\t\taloo model\t\t\t\t\t\t\t\tCreates model\n";
	std::cout << "\t\taloo connect-db\t\t\t\t\t\t\tConnects to "
				 "database\033[0m\n";
}

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
