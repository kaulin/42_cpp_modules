#include <limits>
#include "iter.hpp"

int main(int argc, char** argv) {
	if (argc > 1) {
		std::cout << "Testing template on arg array: \n";
		::iter(argv, argc, printItem);
	}
	else {
		std::string strArray[] = {"All", "your", "base", "are", "belong", "to", "us", "!"};
		int	intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		const int intArrayConst[] = {0, 42, 666};
		std::cout << "Testing template on string array: \n";
		::iter(strArray, 8, printItem);
		std::cout << "Testing template on int array: \n";
		::iter(intArray, 10, printItem);
		std::cout << "Testing template on const int array: \n";
		::iter(intArrayConst, 3, printItem);
	}
	return 0;
}