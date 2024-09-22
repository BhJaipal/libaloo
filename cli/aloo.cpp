#include "create-app.cpp"
#include "model.cpp"
#include "utils.cpp"
#include <cstdlib>
#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/direction.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/requirement.hpp>
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

	// std::cout << "\033[2;36m";
	using namespace ftxui;

	auto commands = Table({
		{std::string("         Commands"), "                  Description"},
		{std::string("    -h | --help | help    "), "Shows this help message"},
		{std::string("create-app"), "Creates C Aloo app template"},
		{"    run [ app | test ]    ", "Runs "
									   "Aloo app/ test build"},
		{"build", "Builds Aloo "
				  "app/ tests"},
		{"clean", "    Removes previous build data and executables    "},
		{"model", "Creates model"},
		{"connect-db", "Connects to "
					   "database"},
	});

	commands.SelectAll().Border(LIGHT);

	// Add border around the first column.
	commands.SelectColumn(0).Border(LIGHT);

	// Make first row bold with a double border.
	commands.SelectRow(0).Decorate(bold);
	commands.SelectRow(0).SeparatorVertical(LIGHT);
	commands.SelectRow(0).Border(DOUBLE);

	auto content = commands.SelectRows(1, -1);

	content.DecorateCellsAlternateColumn(color(Color::SkyBlue1), 2, 0);
	content.DecorateCellsAlternateColumn(center, 2, 0);
	content.DecorateCellsAlternateColumn(bold, 2, 0);

	content.DecorateCellsAlternateColumn(color(Color::GrayDark), 2, 1);
	content.DecorateCellsAlternateColumn(center, 2, 1);

	std::system("clear");
	std::string spaces = "    ";
	for (int i = 0; i < 7; i++) { spaces += "    "; }
	Element document = hbox({
		text(spaces + "   " + "Aloo TUI" + spaces + "   ") |
			color(Color::BlueLight) | border | bold,
	});
	auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
	Render(screen, document);
	screen.Print();

	document = commands.Render();
	screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
	Render(screen, document);
	screen.Print();
}

int main(int argc, char const *argv[]) {
	std::string currWD = "/home/jaipal001/Desktop/files/c-use/libaloo";
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
