#include <limits>
#include "iter.hpp"

void printArgs(char* arg) {
	for (int i = 0; arg[i]; i++)
		std::cout << arg[i];
	std::cout << "\n";
}

void printItem(std::string str) {
	std::cout << str << "\n";
}

void printFlippedInt(int n) {
	int temp = std::numeric_limits<int>::max() + n;
	std::cout << n << " flips to " << temp << "\n";
}

int main(int argc, char** argv) {
	if (argc > 1) {
		std::cout << "Testing template on arg array: \n";
		::iter(argv, argc, printArgs);
	}
	else {
		std::string strArray[] = {"All", "your", "base", "are", "belong", "to", "us", "!"};
		int	intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << "Testing template on string array: \n";
		::iter(strArray, 8, printItem);
		std::cout << "Testing template on int array: \n";
		::iter(intArray, 10, printFlippedInt);
	}
	return 0;
}