///usr/bin/g++ -o aloo.exe aloo.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
	for (int i = 0; i < argc; i++) { std::cout << argv[i] << " "; }
	std::cout << "\n";
	return 0;
}
