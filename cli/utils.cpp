#pragma once
// #define ALOO_TUI
#ifdef ALOO_TUI
#include "ftxui/component/animation.hpp"
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/loop.hpp"
#include "ftxui/component/mouse.hpp"
#include "ftxui/component/receiver.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/task.hpp"
#include "ftxui/dom/canvas.hpp"
#include "ftxui/dom/direction.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/flexbox_config.hpp"
#include "ftxui/dom/linear_gradient.hpp"
#include "ftxui/dom/node.hpp"
#include "ftxui/dom/requirement.hpp"
#include "ftxui/dom/table.hpp"
#include "ftxui/screen/box.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/screen/color_info.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/screen/terminal.hpp"
void help() {
	int cols = 80;
	int lines = 24;

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

	int _ = std::system("clear");
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
	std::vector<std::string> entries{"Create App", "Build", "Run", "Model",
									 "Connect DB"};

	auto screen2 = ScreenInteractive::TerminalOutput();
	int selected = 0;
	MenuOption option;
	option.on_enter = screen2.ExitLoopClosure();
	auto menu = Menu(&entries, &selected, option);

	screen2.Loop(menu);
}
#else
void help() {
	std::cout << "\033[2;36m";
	for (int i = 0; i < 17; i++) { std::cout << "    "; }
	std::cout << "Aloo CLI";
	for (int i = 0; i < 17; i++) { std::cout << "    "; }
	std::cout << "\n";
}
#endif

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
namespace fs = std::filesystem;

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